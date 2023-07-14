cmake_minimum_required(VERSION 3.26.4)

set(PROJECT_NAME Saltman)
set(EXECUTABLE_NAME main)
set(SFML_DIR "D://SFML-2.6.0//lib//cmake//SFML")

project(${PROJECT_NAME} LANGUAGES CXX)



find_package(SFML 2.6.0 COMPONENTS system window graphics network audio REQUIRED)

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} sfml-system sfml-window sfml-graphics)