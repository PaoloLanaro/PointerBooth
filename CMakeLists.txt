cmake_minimum_required(VERSION 3.22)
project(FinalProject)

set(CMAKE_CXX_STANDARD 17)
set(ENV{OPENCV_DIR} "C:\\tools\\opencv\\build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# create a statically linked library named imgLib
add_library(imgLib
        lib/src/Pixel.cpp
)

add_library(jsonLib
        lib/src/FilterPackManager.cpp
)


find_package( OpenCV REQUIRED )

include_directories( ${Open_CV_INCLUDE_DIRS} )

target_include_directories(imgLib PRIVATE lib/include lib/stb)
target_include_directories(jsonLib PRIVATE lib/include lib/nlohmann)

add_executable(${CMAKE_PROJECT_NAME} driver.cpp
        lib/include/filters/GlitchFilter.h
        lib/include/filters/PixelSortFilter.h
        lib/include/filters/GrayScaleFilter.h
        lib/src/GrayScaleFilter.cpp
        lib/include/filters/GaussianBlurFilter.h
        lib/include/filters/SimpleBlurFilter.h
        lib/src/GaussianBlurFilter.cpp
        lib/src/SimpleBlurFilter.cpp
        lib/include/filters/OtsuThresholdingFilter.h
        lib/src/OtsuThresholdingFilter.cpp
        lib/include/filters/ContourFilter.h
        lib/src/ContourFilter.cpp
        lib/include/MatAdapter.h
        lib/src/MatAdapter.cpp
        lib/stb/stb_image.h
        lib/stb/stb_image_write.h
        lib/include/Image.h
        lib/src/Image.cpp
        lib/include/Editor.h
        lib/src/Editor.cpp
        lib/include/Filter.h
        driver.cpp
        lib/src/VideoEnvironment.cpp
        lib/include/filters/PointillismFilter.h
        lib/src/FilterPackManager.cpp
)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)

target_link_libraries( ${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} imgLib jsonLib)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)
