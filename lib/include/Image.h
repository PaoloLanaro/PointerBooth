//
// Created by David on 10/10/2023.
//

#ifndef IMAGELIB_IMAGE_H
#define IMAGELIB_IMAGE_H

#include <string>
#include "Pixel.h"
#include <utility>
using namespace std::rel_ops;

class Image {
    friend class Editor;
private:
    std::string inputPath;
    std::string outputPath;
    Pixel** layout;
    int height, width;
    int numComponents;
    float* convertHDRFormat(unsigned char* data);
    Pixel& pickRandom();
    void recolorSurroundingPixels(int, int, int);
    void colorPlus(int, int, int);
    bool isInBounds(int, int);
public:
    Image(std::string, int);
    Image(int);
    Image(unsigned char*, int, int, int);
    ~Image();
    Image(const Image& copyMe);
    Image(Pixel**, int, int, int);
    Image& operator=(const Image&);
    void open(std::string, int&, int&, int&, int);
    int getWidth();
    int getHeight();
    Pixel** getLayout();
    void setWidth(int);
    void setHeight(int);
    void setupData(unsigned char*);
    unsigned char* flatten();
    void saveAs(std::string);
    Pixel getAvgRGB() const;
    bool operator<(const Image& other);
    bool operator==(const Image& other);
    Pixel calcAvgRGBFromArea(int, int, int, int);
};


#endif //IMAGELIB_IMAGE_H
