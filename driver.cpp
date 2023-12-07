#include <iostream>

using std::cout, std::endl;

#pragma ide diagnostic ignored "EndlessLoop"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/utility.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>
#include "opencv2/videoio.hpp"
#include "PixelSortFilter.h"
#include <opencv2/highgui.hpp>
#include <GlitchFilter.h>
#include <opencv2/video.hpp>
#include "GrayScaleFilter.h"
#include "SimpleBlurFilter.h"
#include "GaussianBlurFilter.h"
#include "OtsuThresholdingFilter.h"
#include "ContourFilter.h"
#include "MatAdapter.h"
#include "Image.h"
#include "Editor.h"
#include "VideoEnvironment.h"


using namespace std;
using namespace cv;


int main() {
    VideoEnvironment ve;
    std::vector<MatrixFilter*> test;
    ve.startVideo(test);
    return 0;
}


