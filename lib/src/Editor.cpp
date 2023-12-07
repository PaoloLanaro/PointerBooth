//
// Created by dbusn on 10/13/2023.
//

#include <iostream>
#include "Editor.h"

const float POINTILLISM_SCALE_FACTOR = .01;

Editor::Editor(Image &a) : toEdit(a) { }

/**
 * Swap 2 pixels by reference
 *
 * @param a
 * @param b
 */
void pixelSwap(Pixel& a, Pixel& b) {
    Pixel c = a;
    a = b;
    b = c;
}

/**
 * Flip image vertically
 */
void Editor::flipVertical() {
    for (int curRow = 0; curRow < toEdit.height / 2; curRow++) {
        for(int curCol = 0; curCol < toEdit.width - 1; curCol++) {
            pixelSwap(toEdit.layout[curRow][curCol], toEdit.layout[toEdit.height - curRow - 1][curCol]);
        }
    }
}

/**
 * Flip image horizontally
 */
void Editor::flipHorizontal() {
    for (int curRow = 0; curRow < toEdit.height; curRow++) {
        for(int curCol = 0; curCol < toEdit.width / 2; curCol++) {
            pixelSwap(toEdit.layout[curRow][curCol], toEdit.layout[curRow][toEdit.width - curCol - 1]);
        }
    }
}

/**
 * Rotate image clockwise
 */
void Editor::rotateClockwise() {
    //init rotated array
    Pixel** rotated = new Pixel*[toEdit.width];
    for (int row = 0; row < toEdit.width; row++) {
        rotated[row] = new Pixel[toEdit.height];
    }
    //make the rotation
    for (int curRow = 0; curRow < toEdit.height; curRow++) {
        for (int curCol = 0; curCol < toEdit.width; curCol++) {
            rotated[curCol][toEdit.height - 1 - curRow] = toEdit.layout[curRow][curCol];
        }
    }
    //delete old array and replace
    for (int curRow = 0; curRow < toEdit.height; curRow++) {
        delete[] toEdit.layout[curRow];
    }
    delete[] toEdit.layout;
    toEdit.layout = rotated;
    int temp = toEdit.height;
    toEdit.height = toEdit.width;
    toEdit.width = temp;

}

/**
 * Rotate image counter-clockwise
 */
void Editor::rotateCounterClockwise() {
    for (int iteration = 0; iteration < 3; iteration++) {
        this->rotateClockwise();
    }
}

/**
 * Given the number of components and RGB value, make the appropriate pixel
 *
 * @param r red val
 * @param g green val
 * @param b blue val
 * @param numComponents number of components
 * @return Pixel
 */
Pixel Editor::makeAppropriatePixel(int r, int g, int b, int numComponents) {
    switch (numComponents) {
        case 2:
            return Pixel(r * .299 + g * .587 + b * .114, 255); //this is the equation to convert RGB to greyscale value
            //we return it with max alpha
        case 3:
            return Pixel(r, g, b);
        case 4:
            return Pixel(r, g, b, 255);
    }
}

/**
 * Add a border around image
 *
 * @param size Size of border in pixels
 * @param r Red value
 * @param g Green value
 * @param b Blue value
 */
void Editor::addBorder(int size, int r, int g, int b) {
    int newWidth = toEdit.width + size * 2;
    int newHeight = toEdit.height + size * 2;

    //init bordered array
    Pixel** bordered = new Pixel*[newHeight];
    for (int row = 0; row < newHeight; row++) {
        bordered[row] = new Pixel[newWidth];
    }

    //fill first and last 'width' rows with color of border
    for (int row = 0; row < newHeight; row++) {
        for(int col = 0; col < newWidth - 1; col++) {
            if ((row <= size || row >= newHeight - size) || (col <= size || col >= newWidth - size))
                bordered[row][col] = makeAppropriatePixel(r, g, b, toEdit.numComponents);
            else {
                //std::cout << "row " << row << " " << "col " << col << std::endl;
                bordered[row][col] = toEdit.layout[row - size][col - size];

                //std::cout << row - size << " " << col - size << std::endl;
            }
        }
    }

    //delete old array and replace
    for (int curRow = 0; curRow < toEdit.height; curRow++) {
        delete[] toEdit.layout[curRow];
    }
    delete[] toEdit.layout;
    toEdit.layout = bordered;
    toEdit.height = newHeight;
    toEdit.width = newWidth;
}


/**
 * Convert image to pointillism style
 */
void Editor::pointillism() {
    int maxRadius = std::min(toEdit.height, toEdit.width) * POINTILLISM_SCALE_FACTOR;

    for(int point = 0; point < toEdit.height * toEdit.width / 10; point++) {
        toEdit.recolorSurroundingPixels(rand() % toEdit.width, rand() % toEdit.height, rand() % maxRadius);
    }
}

/**
 * Handle a provided string request
 *
 * @param request The editing request made
 */
void Editor::processRequest(std::string request) {
    if(request == "flipvert") {
        this->flipVertical();
    } else if (request == "fliphoriz") {
        this->flipHorizontal();
    } else if (request == "rotatec") {
        this->rotateClockwise();
    } else if (request == "rotatecc") {
        this->rotateCounterClockwise();
    } else if (request == "point") {
        this->pointillism();
    }
}
