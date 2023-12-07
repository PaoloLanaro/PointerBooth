# [Pointer Booth](https://github.com/PaoloLanaro/PointerBooth)

by [David Busnel](https://github.com/dbusnel) and [Paolo Lanaro](https://github.com/paololanaro)

A [Photo booth](https://en.wikipedia.org/wiki/Photo_Booth) style application made in C++.
It is capable of displaying multiple filters through a live camera feed and
allows the user to choose through a set of these filters in different orders.

It contains compatibility of STBI image filters to OpenCV matrix image formats. This allows effects like "Pointillism" implemented on STBI data to be implemented in OpenCV video.

## Dependencies

This program requires [OpenCV](https://opencv.org/), [wxWidgets](https://www.wxwidgets.org/), and the STBI image library.

OpenCV is used for its camera capture and video capabilities, wxWidgets is used for GUI, and the STBI library is used for image manipulation.

## Build
 - Ensure all required libraries are installed

## Usage
#### COMMAND LINE MODE
 - Provide a list of your filters you would like applied in order. The available filters are as follows:
   - "contour" - Contour effect
   - "pointillism" - Pointillism effect
   - "gaussianblur" - Gaussian Blur effect
   - "glitch" - Glitch effect [beware of flashing lights]
   - "otsu" - Otsu Thresholding effect
   - "pixelsort" - Vertically sort pixels lexicographically descending
   - "greyscale" - Convert image to greyscale
 - Run the program! The camera feed will open automatically and your filters will be applied.