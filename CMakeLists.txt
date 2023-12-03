cmake_minimum_required(VERSION 3.22)
project(FinalProject)

set(CMAKE_CXX_STANDARD 17)
set(ENV{OPENCV_DIR} "C:\\opencv\\opencv\\build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package( OpenCV REQUIRED )
include_directories( ${Open_CV_INCLUDE_DIRS} )



# include lib/src/.cpp files here
# add_library(project5 todo
#         lib/src/name.cpp todo
# ) todo
# target_include_directories(project5 PRIVATE lib/include lib/tesseract) todo


add_executable(${CMAKE_PROJECT_NAME} driver.cpp
# lib/include/name.h todo
)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries( ${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} )

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE project5) todo
