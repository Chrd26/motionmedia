cmake_minimum_required(VERSION 3.27)
project("MotionMedia" LANGUAGES CXX VERSION 0.1 DESCRIPTION "MotionMedia is a computer vision based app that displays certain media based on detection")

# Installation use otool -L to figure out rpath set rpath for macos with @loader_path
# set rpath for linux with @executable_path
# Rpath can be used to locate library files
set(CMAKE_MACOXS_RPATH ON)
set(CMAKE_INSTALL_RPATH "@loader_path/../../../lib")

add_executable(${PROJECT_NAME} ./src/main.cpp)
