cmake_minimum_required(VERSION 3.12)
project(Lab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab5
        UtPod.h
        UtPodDriver.cpp
        UtPod.cpp
        song.cpp
        song.h)
