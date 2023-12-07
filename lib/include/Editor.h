//
// Created by dbusn on 10/13/2023.
//

#ifndef IMAGELIB_EDITOR_H
#define IMAGELIB_EDITOR_H


#include <string>
#include "Image.h"

class Editor {
private:
    Image& toEdit;
    Pixel makeAppropriatePixel(int r, int g, int b, int numComponents);
public:
    explicit Editor(Image&);
    void flipVertical();
    void flipHorizontal();
    void rotateClockwise();
    void rotateCounterClockwise();
    void addBorder(int, int, int, int);
    void pointillism();
    void processRequest(std::string);
};


#endif //IMAGELIB_EDITOR_H
