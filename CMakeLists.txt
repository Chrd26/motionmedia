cmake_minimum_required(VERSION 3.27)
project("MotionMedia" LANGUAGES CXX VERSION 0.1 DESCRIPTION "MotionMedia is a computer vision based app that displays certain media based on detection")
set(CMAKE_CXX_STANDARD 20)

# Handle Submodules: https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html 
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY "./modules/"
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

# Has OenCV been downloaded?
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/modules/opencv/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# Installation use otool -L to figure out rpath set rpath for macos with @loader_path
# set rpath for linux with @executable_path
# Rpath can be used to locate library files
set(CMAKE_MACOXS_RPATH ON)
set(CMAKE_INSTALL_RPATH "@loader_path/../../../lib")

# find opencv
set(OpenCV_DIR "${PROJECT_SOURCE_DIR}/modules/opencv/build_opencv/")
message(STATUS "OpenCV_DIR: ${OpenCV_DIR}")
add_subdirectory("${PROJECT_SOURCE_DIR}/modules/opencv")
find_package(OpenCV REQUIRED)


# Build
add_executable(${PROJECT_NAME} ./src/main.cpp)
# Add opencv to linker
target_link_libraries(${PROJECT_NAME} PRIVATE opencv::opencv)
