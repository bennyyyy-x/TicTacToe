cmake_minimum_required(VERSION 3.14)
project(tictactoe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        board.cpp
        board.hpp
        game.cpp
        game.hpp
)
add_executable(tictactoe ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(tictactoe sfml-system sfml-window sfml-graphics sfml-audio sfml-network)