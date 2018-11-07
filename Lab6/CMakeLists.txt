cmake_minimum_required(VERSION 3.12)
project(Lab6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab6
        card.h
        go_fish.cpp
        deck.h
        player.h
        card.cpp
        deck.cpp
        player.cpp)
