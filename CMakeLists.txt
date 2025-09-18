cmake_minimum_required(VERSION 4.0)
project(CXXFS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CXXFS main.cpp
        Program/drive.cpp
        Program/drive.h
        Program/file.cpp
        Program/file.h
)
