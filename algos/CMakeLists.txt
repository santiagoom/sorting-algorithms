cmake_minimum_required(VERSION 3.14)
project(sorting-algorithms)

set(CMAKE_CXX_STANDARD 14)

#add_executable()
include_directories(cpp/cppUtils/utils)
add_subdirectory(cpp/HeapSort)
add_subdirectory(cpp/QuickSort)
