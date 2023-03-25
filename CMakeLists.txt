cmake_minimum_required(VERSION 3.24)
project(PAMImage)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

file(GLOB SRC include/PAMImage/* src/*)
add_library(PAMImage ${SRC})
include_directories(include)

file(GLOB TESTS tests/*)
add_executable(PAMImageTests ${TESTS})
target_link_libraries(PAMImageTests PAMImage)
