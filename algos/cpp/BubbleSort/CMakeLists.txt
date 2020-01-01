cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        ../cppUtils/utils/myutils.h
        ../cppUtils/utils/myutils.cpp
        )
add_executable(BubbleSort_practise BubbleSort_practise.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(OptimizedImplementation OptimizedImplementation.cpp ${SOURCE_FILES} ${SOURCES})

