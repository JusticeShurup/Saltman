cmake_minimum_required(VERSION 3.26.4)

set(PROJECT_NAME Saltman)
set(EXECUTABLE_NAME main)
set(SFML_DIR "D://SFML-2.6.0//lib//cmake//SFML")
set(BOOST_ROOT "C://Boost")
project(${PROJECT_NAME} LANGUAGES CXX)


file(GLOB SOURCES "src/*.cpp"
                "src/Containers/*.cpp")

find_package(SFML 2.6.0 COMPONENTS system window graphics network audio REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_link_libraries(${EXECUTABLE_NAME} sfml-system sfml-window sfml-graphics)
find_package(Boost 1.82.0 COMPONENTS filesystem REQUIRED)
message(STATUS "BOOST_COMPILER ${BOOST_COMPILER}")
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
endif()