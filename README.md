# [Pointer Booth](https://github.com/PaoloLanaro/PointerBooth) 
<img src="https://github.com/PaoloLanaro/PointerBooth/assets/126436246/83e3280a-5e33-4556-aae4-e16db194669e" align = "right" alt="Pointer Booth logo by David Busnel" width="84" height="83">

by [David Busnel](https://github.com/dbusnel) and [Paolo Lanaro](https://github.com/paololanaro) 

A [Photo booth](https://en.wikipedia.org/wiki/Photo_Booth) style application made in C++.
It is capable of displaying multiple filters through a live camera feed, and
allows the user to choose through a set of these filters in different orders.

It contains compatibility of STBI image array formats to OpenCV matrix image formats. 
This allows effects like Pointillism functionality, implemented in STBI, to be implemented in OpenCV video.

The user can save different combinations of filters through the JSON file serialization of filter containers.

## Dependencies

This program requires [OpenCV](https://opencv.org/), [JSON for Modern C++](https://github.com/nlohmann/json), and the [STBI image library](https://github.com/nothings/stb) to function.

- *OpenCV* for its camera capture and video capabilities.
- *JSON for Modern C++* to read and write filter configurations.
- *STBI library* for image (and more specifically pixel) manipulation.

## Build
 - Ensure all required libraries are installed.

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
   - `contour` - Contour effect (To contour you must first Otsu threshold on a greyscale image)
   - `pointillism` - Pointillism effect
   - `gaussianblur` - Gaussian Blur effect
   - `glitch` - Glitch effect [beware of flashing lights]
   - `otsu` - Otsu Thresholding effect
   - `pixelsort` - Vertically sort pixels lexicographically descending
   - `greyscale` - Convert image to greyscale
 - Run the program! The camera feed will open automatically and your filters will be applied.
   - Exit the camera feed with the `Esc` key on your keyboard.
   - Saved configurations will not appear until camera is closed.

## Examples

### Live Feed
Command line arg: N/A

<img width="480" alt="LiveFeed" src="https://github.com/PaoloLanaro/PointerBooth/assets/126436246/245d29f9-1ec2-4137-a726-8c1e59fbf8f8">

### Live Pointillism
Command line arg: `pointillism`

<img width="482" alt="LivePointillism" src="https://github.com/PaoloLanaro/PointerBooth/assets/126436246/c9215d2a-f517-4d5f-954e-f05442e7f2f2">

### Live PixelSort Pointillism combination
Command line arg: `pixelsort pointillism`

<img width="480" alt="PixelSortPointillism" src="https://github.com/PaoloLanaro/PointerBooth/assets/126436246/39de243c-485a-49b1-8542-93cabb6a818d">
