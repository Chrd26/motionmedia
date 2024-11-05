cmake_minimum_required(VERSION 3.27)
project("MotionMedia" LANGUAGES CXX VERSION 0.1 DESCRIPTION "MotionMedia is a computer vision based app that displays certain media based on detection")
set(CMAKE_CXX_STANDARD 20)
# add extra include directories
include_directories(/usr/local/Cellar/opencv/4.10.0_4/include/opencv4)
include_directories(${OpenCV_INCLUDE_DIRS})

# Installation use otool -L to figure out rpath set rpath for macos with @loader_path
# set rpath for linux with @executable_path
# Rpath can be used to locate library files
#set(CMAKE_MACOXS_RPATH ON)
#set(CMAKE_INSTALL_RPATH "@loader_path/../../../lib")

# find opencv
set(OpenCV_DIR "/usr/local/Cellar/opencv/4.10.0_4/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)

# Build
add_executable(	${PROJECT_NAME} ./src/main.cpp
				./src/capture.h ./src/capture.cpp
				./src/videoplayer.h ./src/videoplayer.cpp 
				./src/detector.h ./src/detector.cpp)

# Add opencv to linker this is for the homebrew version. I have been unable to 
# use it as a submodule due to a weird error with the libjpeg-turbo.
# It might fixed in the future.
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# it was not possible to symlink opencv I because the licenses file was not writable
# First run the following:
# sudo chown -R `whoami`:admin /usr/local/bin
# sudo chown -R `whoami`:admin /usr/local/share
# sudo chown -R `whoami`:admin /usr/local/opt
# Then:
# brew link opencv
