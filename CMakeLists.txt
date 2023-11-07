cmake_minimum_required(VERSION 3.5.1)

project(games_project)

set (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(${SRC_DIR}/Starcraft)
add_subdirectory(${SRC_DIR}/Warcraft)
add_subdirectory(${SRC_DIR}/Counter_Strike)