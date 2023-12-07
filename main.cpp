#include <iostream>

#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include "PixelSortFilter.h"
#include "ScrambleFilter.h"
#include <opencv2/highgui.hpp>
#include <GlitchFilter.h>
#include "GrayScaleFilter.h"
#include "SimpleBlurFilter.h"
#include "GaussianBlurFilter.h"
#include "OtsuThresholdingFilter.h"
#include "ContourFilter.h"
#include "MatAdapter.h"
#include "Image.h"

using std::cout, std::endl, cv::Mat;

int videoCapture();

void imageTest();

int main() {
    return videoCapture();

//    imageTest();

    return 0;
}

void imageTest() {
    Mat img = cv::imread("../test_images/finger-up.jpg");
    MatAdapter test;
    Image testImg(test.convertToStbiArray(img, 3), 3, img.rows, img.cols / 3);

    while (true) {
        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }

}

int videoCapture() {

    cv::VideoCapture videoCam(0);
    videoCam.set(cv::CAP_PROP_SETTINGS, 1);

    if (!videoCam.isOpened()) {
        cout << "Can't open the camera." << endl;
        return -1;
    }

    Mat currFrame;

    while(true) {
        videoCam >> currFrame;
        cv::imshow("Initial Frame", currFrame); // original image

        // greyscale filter
        Mat grayFrame = currFrame.clone();
        GrayScaleFilter gsf;
        gsf.edit(grayFrame);

        cv::imshow("Gray frame", grayFrame);

        // simple blur
        Mat blurredFrame = currFrame.clone();
        SimpleBlurFilter sbf;
        sbf.edit(blurredFrame);

        cv::imshow("Simple Blurred Frame", blurredFrame);

        // gaussian blur
        Mat gaussBlurFrame = currFrame.clone();
        GaussianBlurFilter gbf;
        gbf.edit(gaussBlurFrame);

        cv::imshow("Gaussian Blurred Frame", gaussBlurFrame);

        // combines gray and simple blur filters
        Mat grayGaussian = grayFrame.clone();
        sbf.edit(grayGaussian);

        // thresholding for pre contouring REQUIRED TO CONTOUR
        OtsuThresholdingFilter otf;
        otf.edit(grayGaussian);

        cv::imshow("simple otsu thresholding (binarization) ", grayGaussian);

        //some sort of polymorphism for filters here
        //they can be stacked too-- maybe some sort of command for them
        //example usage

        GlitchFilter gf;
        PixelSortFilter psf;
        ScrambleFilter sf;

//        gf.edit(&currFrame);
//        psf.edit(&currFrame);
//        sf.edit(&currFrame);

        // contour filter
        Mat ioFrame = currFrame.clone();
        ContourFilter cf(ioFrame);
        cf.edit(grayGaussian);

        cv::imshow("final", ioFrame);

        int key = cv::waitKey(1);
        if (key == 27) {        // esc key
            break;
        }
    }
    return 0;
}


// Todo: wxWidgets
//#include "PointerBoothWindow.h"
//
//#include <wx/wxprec.h>
//#ifndef WX_PRECOMP
//#include <wx/wx.h>
//#endif
//
//class PointerBoothApp: public wxApp {
//public:
//    virtual bool OnInit();
//};
//
//wxIMPLEMENT_APP(PointerBoothApp);
//bool PointerBoothApp::OnInit()
//{
//    auto *frame = new PointerBoothWindow("Pointer Booth!", wxPoint(250, 250), wxSize(500, 500));
//    frame->Show(true);
//    return true;
//}