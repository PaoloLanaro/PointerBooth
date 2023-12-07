cmake_minimum_required(VERSION 3.22)
project(FinalProject)

set(CMAKE_CXX_STANDARD 17)
set(ENV{OPENCV_DIR} "C:\\tools\\opencv\\build")
set(ENV{wxWidgets_ROOT_DIR} "C:\\wxWidgets-3.2.4")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# create a statically linked library named libimgLib
add_library(imgLib
        lib/src/Pixel.cpp
)

find_package( OpenCV REQUIRED )
find_package( wxWidgets REQUIRED COMPONENTS core base )
include_directories( ${Open_CV_INCLUDE_DIRS} )
include(${wxWidgets_USE_FILE})
target_include_directories(imgLib PRIVATE lib/include lib/stb)

# include lib/src/.cpp files here
# add_library(project5 todo
#         lib/src/name.cpp todo
# ) todo


add_executable(${CMAKE_PROJECT_NAME} main.cpp
        lib/include/GlitchFilter.h
        lib/include/PixelSortFilter.h
        lib/src/Filter.cpp
        lib/include/Filter.h
        lib/include/ScrambleFilter.h
        lib/include/GrayScaleFilter.h
        lib/src/GrayScaleFilter.cpp
        lib/include/GaussianBlurFilter.h
        lib/include/SimpleBlurFilter.h
        lib/src/GaussianBlurFilter.cpp
        lib/src/SimpleBlurFilter.cpp
        lib/include/OtsuThresholdingFilter.h
        lib/src/OtsuThresholdingFilter.cpp
        lib/include/ContourFilter.h
        lib/src/ContourFilter.cpp
        lib/include/MatAdapter.h
        lib/src/MatAdapter.cpp
        lib/stb/stb_image.h
        lib/stb/stb_image_write.h
        lib/include/Image.h
        lib/src/Image.cpp
        lib/include/Editor.h
        lib/src/Editor.cpp
        lib/include/PointerBoothWindow.h
        lib/src/PointerBoothWindow.cpp
        # lib/include/name.h todo
)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)

target_link_libraries( ${CMAKE_PROJECT_NAME} ${wxWidgets_LIBRARIES} ${OpenCV_LIBS} imgLib)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE project5) todo
