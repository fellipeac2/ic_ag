cmake_minimum_required(VERSION 3.8)
project(ic)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        ail/binary/chrm_binary.hpp
        ail/binary/pop_binary.hpp

        src/evaluation.cpp src/evaluation.h
        src/sample.cpp)

include_directories(.)
include_directories(src)
include_directories(ail)

add_executable(ic ${SOURCE_FILES})