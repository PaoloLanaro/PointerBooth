//
// Created by David on 10/10/2023.
//

#include <iostream>
#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"

/**
 * Open the image at the provided path
 *
 * @param input Input path
 * @param heightOutput Output var for height
 * @param widthOutput Output var for width
 * @param numComponentsOutput Output var for number of components
 * @param numComponentsInput Number of components desired
 */
void Image::open(std::string input, int& heightOutput, int& widthOutput, int& numComponentsOutput,
                 int numComponentsInput) {
    this->inputPath = input;
    setupData(stbi_load(input.c_str(), &widthOutput, &heightOutput, &numComponentsOutput,
              numComponentsInput));
}

/**
 * Create an image with a provided file path
 *
 * @param inputPath file path
 * @param numComponents number of components
 */
Image::Image(std::string inputPath, int numComponents) {
    open(inputPath, this->height, this->width, this->numComponents, numComponents);
}

/**
 * Create an image with just the number of components
 *
 * @param numComponents
 */
Image::Image(int numComponents) {
    this->numComponents = numComponents;
}

/**
 * Create an image with an array of pixels, number of components, and dimensions
 */
 Image::Image(Pixel** layout, int numComponents, int height, int width) : layout(layout), numComponents(numComponents) {
     this->height = height;
     this->width = width;
 }

/**
 * Convert the 1D array of key into a 2D array of pixels
 */
void Image::setupData(unsigned char* data) {

    //create the array
    this->layout = new Pixel*[height];
    for (int row = 0; row < this->height; row++) {
        this->layout[row] = new Pixel[this->width];
    }

    int numDataVals = height * width * numComponents;
    //fill the array
    for (int pixRow = 0; pixRow < this->height; pixRow++) {
        for (int pixCol = 0; pixCol < width; pixCol++) {
            this->layout[pixRow][pixCol] = Pixel(data, this->numComponents, pixRow, pixCol, width);
        }
    }
}

/**
 * Set height of image
 *
 * @param height
 */
void Image::setHeight(int height) {
    this->height = height;
}

/**
 * Set width of image
 *
 * @param width
 */
void Image::setWidth(int width) {
    this->width = width;
}

/**
 * Get layout of image
 *
 * @return layout
 */
Pixel **Image::getLayout() {
    return this->layout;
}

/**
 * Get width of image
 *
 * @return width
 */
int Image::getWidth() {
    return this->width;
}

/**
 * Get height of image
 *
 * @return height
 */
int Image::getHeight() {
    return this->height;
}

/**
 * Flatten image into 1D array
 *
 * @return 1D array of image key
 */
unsigned char* Image::flatten() {
    int size = this->height * this->width * this->numComponents;
    int flatIndex = 0;
    unsigned char* flattened = new unsigned char[size];
    for (int curRow = 0; curRow < this->height; curRow++) {
        for (int curCol = 0; curCol < this->width; curCol++) {
            switch(numComponents) { //NOTE: I would change this design if class extensions were permissible
                case 2:
                    flattened[flatIndex] = this->layout[curRow][curCol].getGrey();
                    flattened[flatIndex + 1] = this->layout[curRow][curCol].getAlpha();
                    break;
                case 3:
                    flattened[flatIndex] = this->layout[curRow][curCol].getRed();
                    flattened[flatIndex + 1] = this->layout[curRow][curCol].getGreen();
                    flattened[flatIndex + 2] = this->layout[curRow][curCol].getBlue();
                    break;
                case 4:
                    flattened[flatIndex] = this->layout[curRow][curCol].getRed();
                    flattened[flatIndex + 1] = this->layout[curRow][curCol].getGreen();
                    flattened[flatIndex + 2] = this->layout[curRow][curCol].getBlue();
                    flattened[flatIndex + 3] = this->layout[curRow][curCol].getAlpha();
                    break;
            }
            flatIndex += numComponents;
        }
    }
    return flattened;
}


/**
 * Get file extension, assuming proper formatting
 */
std::string getFormat(std::string filename) {
    bool reading = false;
    std::string extension = "";
    for (int i = 0; i < filename.length(); i++) {
        if (reading) {
            extension += std::tolower(filename[i]);
        }
        if (filename[i] == '.')
            reading = true;
    }
    return extension;
}

/**
 * Save image as provided name
 *
 * @param outputStr
 */
void Image::saveAs(std::string outputStr) {
    std::string filetype = getFormat(outputStr);
    //std::cout << filetype;
    unsigned char* newData = this->flatten();
    if (filetype == "png") {
        stbi_write_png(outputStr.c_str(), this->width,
                       this->height,
                       this->numComponents, newData,
                       this->width * this->numComponents * sizeof (unsigned char));
        //std::cout << "success!";
    } else if (filetype == "jpg") {
        stbi_write_jpg(outputStr.c_str(), this->width, this->height,
                       this->numComponents, newData, 100);
    } else if (filetype == "bmp") {
        stbi_write_bmp(outputStr.c_str(), this->width, this->height,
                       this->numComponents, newData);
    } else if (filetype == "tga") {
        stbi_write_tga(outputStr.c_str(), this->width, this->height,
                       this->numComponents, newData);
    } else if (filetype == "hdr") {
        float* hdrVer = convertHDRFormat(newData);
        stbi_write_hdr(outputStr.c_str(), this->width, this->height,
                       this->numComponents, hdrVer);
        delete[] hdrVer;
    }
    delete[] newData;
}

/**
 * Convert image key to HDR format
 *
 * @param data array of unsigned char key
 * @return array of float key for HDR writing
 */
float* Image::convertHDRFormat(unsigned char* data) {
    int size = this->height * this->width * this->numComponents;
    float* revisedData = new float[size];
    for (int index = 0; index < size; index++) {
        revisedData[index] = static_cast<float>(data[index]);
    }
    return revisedData;
}

/**
 * Destructor -- get rid of allocated memory
 */
Image::~Image() {
    for (int curRow = 0; curRow < this->height; curRow++) {
        delete[] this->layout[curRow];
        this->layout[curRow] = nullptr;
    }
    delete[] this->layout;
    this->layout = nullptr;
}

/**
 * Copy -- make copy of another Image
 */
Image::Image(const Image &copyMe) {
    //create the array
    this->height = copyMe.height;
    this->width = copyMe.width;
    this->numComponents = copyMe.numComponents;
    this->outputPath = copyMe.outputPath;
    this->inputPath = copyMe.inputPath;
    this->layout = new Pixel*[height];
    for (int row = 0; row < this->height; row++) {
        this->layout[row] = new Pixel[this->width];
    }

    //fill the array
    for (int pixRow = 0; pixRow < this->height; pixRow++) {
        for (int pixCol = 0; pixCol < width; pixCol++) {
            this->layout[pixRow][pixCol] = copyMe.layout[pixRow][pixCol];
        }
    }
}

/**
 * Override equals operator
 */
 Image& Image::operator=(const Image& arg) {
    if (this != &arg) {
        for (int curRow = 0; curRow < this->height; curRow++) {
            delete[] this->layout[curRow];
        }
        delete[] this->layout;
        //copy the object
        this->height = arg.height;
        this->width = arg.width;
        this->numComponents = arg.numComponents;
        this->outputPath = arg.outputPath;
        this->inputPath = arg.inputPath;
        this->layout = new Pixel*[height];
        for (int row = 0; row < this->height; row++) {
            this->layout[row] = new Pixel[this->width];
        }

        //fill the array
        for (int pixRow = 0; pixRow < this->height; pixRow++) {
            for (int pixCol = 0; pixCol < width; pixCol++) {
                this->layout[pixRow][pixCol] = arg.layout[pixRow][pixCol];
            }
        }
    }
    return *this;
 }

/**
 * Pick a random pixel
 *
 * @return reference to random pixel
 */
Pixel& Image::pickRandom() {
    int xPos = rand() % this->width;
    int yPos = rand() % this->height;
    return this->layout[yPos][xPos];
}

/**
 * Check if a given coordinate is in bounds
 *
 * @param x x Coord
 * @param y y Coord
 * @return boolean
 */
bool Image::isInBounds(int x, int y) {
    return x >= 0 && y >= 0 && x < this->width && y < this->height;
}

/**
 * Create plus shape for pointillism
 */
void Image::colorPlus(int centerX, int centerY, int radius) {
    for (int i = 1; i <= radius; i++) {
        if(isInBounds(centerX + i, centerY + 1)) {
            layout[centerY + 1][centerX + i] = layout[centerY][centerX];
        }
        if(isInBounds(centerX - i, centerY + 1)) {
            layout[centerY + 1][centerX - i] = layout[centerY][centerX];
        }
        if(isInBounds(centerX, centerY + i)) {
            layout[centerY + i][centerX] = layout[centerY][centerX];
        }
        if(isInBounds(centerX, centerY - i)) {
            layout[centerY - i][centerX] = layout[centerY][centerX];
        }
    }
}

/**
 * Create diamond surrounding provided point
 *
 * @param centerX x val
 * @param centerY y val
 * @param radius size of diamond
 */
void Image::recolorSurroundingPixels(int centerX, int centerY, int radius) {
    int curX = centerX, curY = centerY;
    for(int i = 1; i <= radius; i++) {
        //go up
        curY--;
        if (isInBounds(curX, curY)) {
            layout[curY][curX] = layout[centerY][centerX];
        }

        //top right side
        curX++;
        curY++;
        for (int blockNum = 0; blockNum < i; blockNum++) {
            if (isInBounds(curX, curY)) {
                layout[curY][curX] = layout[centerY][centerX];
            }
            curX++;
            curY++;
        }

        //bottom right side
        curX--;
        curY++;
        for (int blockNum = 0; blockNum < i; blockNum++) {
            if (isInBounds(curX, curY)) {
                layout[curY][curX] = layout[centerY][centerX];
            }
            curX--;
            curY++;
        }

        //bottom left side
        curX--;
        curY--;
        for (int blockNum = 0; blockNum < i; blockNum++) {
            if (isInBounds(curX, curY)) {
                layout[curY][curX] = layout[centerY][centerX];
            }
            curX--;
            curY--;
        }

        //top left side
        curX++;
        curY--;
        for (int blockNum = 0; blockNum < i; blockNum++) {
            if (isInBounds(curX, curY)) {
                layout[curY][curX] = layout[centerY][centerX];
            }
            curX++;
            curY--;
        }
    }
    colorPlus(centerX, centerY, radius);
}

/**
 * Get the average RGB of the image
 *
 * @return a pixel with the average values
 */
Pixel Image::getAvgRGB() const {
    int* avgColor = new int[3] {0, 0, 0};
    int count = 0;
    for (int curRow = 0; curRow < this->height; curRow++) {
        for (int curCol = 0; curCol < this->width; curCol++) {
            Pixel current = this->layout[curRow][curCol];
            avgColor[0] += current.getRed();
            avgColor[1] += current.getGreen();
            avgColor[2] += current.getBlue();
            count++;
        }
    }
    Pixel output(avgColor[0] / count, avgColor[1] / count, avgColor[2] / count);
    delete[] avgColor;
    return output;
}

//bool Image::operator<(const Image& other) {
//    return this->getAvgRGB() < other.getAvgRGB();
//}
//
//bool Image::operator==(const Image& other) {
//    return this->getAvgRGB() == other.getAvgRGB();
//}

Pixel Image::calcAvgRGBFromArea(int x0, int y0, int x1, int y1) {
    int rVal = 0, gVal = 0, bVal = 0;
    int count = 0;
    for (int curRow = y0; curRow < y1 && curRow < this->height; curRow++) {
        for (int curCol = x0; curCol < x1 && curCol < this->width; curCol++) {
            rVal += this->layout[curRow][curCol].getRed();
            gVal += this->layout[curRow][curCol].getGreen();
            bVal += this->layout[curRow][curCol].getBlue();
            count++;
        }
    }
    return Pixel(rVal / count, gVal / count, bVal / count);
}

/**
 * Constructor for provided data
 *
 * @param data data of image
 * @param height height in pixels
 * @param width width in pixels
 * @param numComponents number of components
 */
Image::Image(unsigned char* data, int height, int width, int numComponents) : height(height), width(width), numComponents(numComponents) {
    setupData(data);
}





