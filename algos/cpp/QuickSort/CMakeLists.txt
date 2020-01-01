cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        ../cppUtils/utils/myutils.h
        ../cppUtils/utils/myutils.cpp
        )
add_executable(quickSort quickSort.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(quicksort_practise quicksort_practise.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(quicksort_practise_v2 quicksort_practise_v2.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(quicksort_practise_v3 quicksort_practise_v3.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(QuickSort_geek QuickSort_geek.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(QuickSort_geek_debug QuickSort_geek_debug.cpp ${SOURCE_FILES} ${SOURCES})

