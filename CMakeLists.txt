cmake_minimum_required(VERSION 3.1)
project(TriangulateMonotonePolygon)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")

set(SOURCE_FILES
        src/Args.cxx
        src/IO.cxx
        src/predicates.c
        src/TriangulationMonotonePolygon.cxx
        src/main.cxx)

add_executable(triangulateMonotonePolygon ${SOURCE_FILES})
target_include_directories(triangulateMonotonePolygon PUBLIC ./include)
