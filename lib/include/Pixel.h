#ifndef IMAGELIB_PIXEL_H
#define IMAGELIB_PIXEL_H

#include <string>
#include <utility>
using namespace std::rel_ops;

class Pixel {
private:
    int grey, red, green, blue, alpha;
public:
    Pixel();
    Pixel(int);
    Pixel(int, int);
    Pixel(int, int, int);
    Pixel(int, int, int, int);
    Pixel(unsigned char*, int, int, int, int);
    int numComponents;
    std::string toString();
    int getGrey();
    int getRed();
    int getGreen();
    int getBlue();
    int getAlpha();
//    bool operator<(const Pixel& other);
//    bool operator==(const Pixel& other);
//    bool operator!=(const Pixel& other) {
//        return !(*this == other);
//    }
//    bool operator>(const Pixel& other) {
//        return !(*this < other) && *this != other;
//    }
//    bool operator>=(const Pixel& other) {
//        return !(*this < other);
//    }
//    bool operator<=(const Pixel& other) {
//        return !(*this > other);
//    }
};


#endif //IMAGELIB_PIXEL_H
