cmake_minimum_required(VERSION 3.8)
project(Uncertain)

set(CMAKE_CXX_STANDARD 11)

#set(BOOST_ROOT "D:/Dropbox/boost_1_65_1/boost_1_65_1")
set (BOOST_ROOT "/home/jhkim/boost_1_65_1")

find_package(Boost 1.65.1)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
else()
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
endif()

set(SOURCE_FILES
    Algorithms/knn.cpp
    global.hpp
    loader.cpp
    loader.h
    uncertainGraph.cpp
    uncertainGraph.h
    vertex.cpp
    vertex.h pwg.h pwg.cpp)

add_executable(Uncertain ${SOURCE_FILES})

