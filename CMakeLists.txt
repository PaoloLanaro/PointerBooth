cmake_minimum_required(VERSION 3.22)
project(TypeTestCheat)

set(CMAKE_CXX_STANDARD 17)

# include lib/src/.cpp files here
# add_library(project5 todo
#         lib/src/name.cpp todo
# ) todo
# target_include_directories(project5 PRIVATE lib/include lib/tesseract) todo


add_executable(${CMAKE_PROJECT_NAME} driver.cpp
# lib/include/name.h todo
)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE project5) todo
