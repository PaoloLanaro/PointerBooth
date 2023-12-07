# [Pointer Booth](https://github.com/PaoloLanaro/PointerBooth)

by [David Busnel](https://github.com/dbusnel) and [Paolo Lanaro](https://github.com/paololanaro)

A [Photo booth](https://en.wikipedia.org/wiki/Photo_Booth) style application made in C++.
It is capable of displaying multiple filters through a live camera feed and
allows the user to choose through a set of these filters in different orders.

It contains compatibility of STBI image filters to OpenCV matrix image formats. This allows effects like "Pointillism" implemented on STBI data to be implemented in OpenCV video.

The user can save different combinations of filters through the JSON file serialization of filter containers.

## Dependencies

This program requires [OpenCV](https://opencv.org/), [JSON for Modern C++](https://github.com/nlohmann/json), and the STBI image library to function.

*OpenCV* is used for its camera capture and video capabilities, *JSON for Modern C++* is used to read and write filter configurations, and the STBI library is used for image manipulation.

## Build
 - Ensure all required libraries are installed

## Usage
#### COMMAND LINE MODE
 - If you would like to open a configuration, provide -o or --open as an argument.
   - This can be anywhere in your arguments list, though additional arguments would be redundant.
   - You will be prompted in the terminal for additional information.
     - Have the directory to your .json file prepared!
 - If you would like to save a configuration, provide -s or --s as an argument
   - This can be anywhere in your arguments list.
   - You will be prompted in the terminal for additional information.
     - Have your filename and location prepared!
 - Provide a list of your filters you would like applied in order. The available filters are as follows:
   - "contour" - Contour effect
   - "pointillism" - Pointillism effect
   - "gaussianblur" - Gaussian Blur effect
   - "glitch" - Glitch effect [beware of flashing lights]
   - "otsu" - Otsu Thresholding effect
   - "pixelsort" - Vertically sort pixels lexicographically descending
   - "greyscale" - Convert image to greyscale
 - Run the program! The camera feed will open automatically and your filters will be applied.