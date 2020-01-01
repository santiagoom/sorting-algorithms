cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        ../cppUtils/utils/myutils.h
        ../cppUtils/utils/myutils.cpp
        )

add_executable(InsertionSort_geek InsertionSort_geek.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(insertionsort_practise insertionsort_practise.cpp ${SOURCE_FILES} ${SOURCES})

