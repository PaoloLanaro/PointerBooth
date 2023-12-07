//
// Created by MARK FONTENOT on 10/4/23.
//

#include "Pixel.h"

/**
 * Default pixel, this should not be called outside initialization
 * Represents emptiness
 */
 Pixel::Pixel() {
     this->grey = 0;
     this->alpha = 0;
     this->numComponents = 2;
 }

/**
 * Pixel with two components, grey and alpha
 *
 * @param grey grey value
 * @param alpha alpha value
 */
Pixel::Pixel(int grey, int alpha) {
    this->grey = grey;
    this->alpha = alpha;
    this->numComponents = 2;
}

/**
 * Pixel with three components
 *
 * @param red The value for red
 * @param green The value for green
 * @param blue The value for blue
 */
Pixel::Pixel(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->numComponents = 3;
}

/**
 * Pixel with four components
 *
 * @param red The value for red
 * @param green The value for green
 * @param blue The value for blue
 * @param alpha The value for alpha
 */
Pixel::Pixel(int red, int green, int blue, int alpha) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
    this->numComponents = 4;
}

/**
 * Pixel with a provided number of components, array of key
 * to read from, and starting position.
 */
Pixel::Pixel(unsigned char* data, int numComponents, int rowNum, int colNum, int width) {
    int startIndex = (rowNum * width * numComponents) + colNum * numComponents;
    switch (numComponents) {
        case 2:
            *this = Pixel(data[startIndex], data[startIndex + 1]);
            break;
        case 3:
            *this = Pixel(data[startIndex], data[startIndex + 1],
                          data[startIndex + 2]);
            break;
        case 4:
            *this = Pixel(data[startIndex], data[startIndex + 1],
                          data[startIndex + 2], data[startIndex + 3]);
            break;
        default:
            *this = Pixel();
    }
}

/**
     * Print pixel information as a string
     */
std::string Pixel::toString() {
    std::string output = "";
    switch (this->numComponents) {
        case 2:
            output += "G: " + std::to_string(this->grey) + " A: "
                    + std::to_string(this->alpha);
            break;
        case 3:
            output += "R: " + std::to_string(this->red)
                    + " G: " + std::to_string(this->green)
                    + " B: " + std::to_string(this->blue);
            break;
        case 4:
            output += "R: " + std::to_string(this->red)
                    + " G: "
                    + std::to_string(this->green) + " B: "
                    + std::to_string(this->blue)
                      + " A: " + std::to_string(this->alpha);
            break;
    }
    return output;
}

/**
 * Get grey value
 *
 * @return grey
 */
int Pixel::getGrey() {
    return this->grey;
}

/**
 * Get green value
 *
 * @return green
 */
int Pixel::getGreen() {
    return this->green;
}

/**
 * Get red value
 * @return red
 */
int Pixel::getRed() {
    return this->red;
}

/**
 * Get blue value
 * @return blue
 */
int Pixel::getBlue() {
    return this->blue;
}

/**
 * Get alpha value
 * @return alpha
 */
int Pixel::getAlpha() {
    return this->alpha;
}

//bool Pixel::operator<(const Pixel &other) {
//    // Define the comparison logic.
//    if (this->red < other.red) {
//        return true;
//    } else if (this->red > other.red) {
//        return false;
//    } else if (this->green < other.green) {
//        return true;
//    } else if (this->green > other.green) {
//        return false;
//    } else {
//        return this->blue < other.blue;
//    }
//}
//
//bool Pixel::operator==(const Pixel &other) {
//    return this->red == other.red
//        && this->green == other.green
//        && this->blue == other.blue;
//}





