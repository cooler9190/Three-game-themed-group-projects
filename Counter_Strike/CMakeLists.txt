cmake_minimum_required(VERSION 3.5.1)

project(Counter_Strike)

#Da napravim glaven CMake_helpers a ne da ima edin i susht fail vuv vsqka igra.
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
                ${PROJECT_ROOT}/src/gunsSrc/DesertEagle.cpp
                ${PROJECT_ROOT}/src/GameController.cpp
                ${PROJECT_ROOT}/src/gunsSrc/Glock.cpp
                ${PROJECT_ROOT}/src/main.cpp
                ${PROJECT_ROOT}/src/gunsSrc/Pistol.cpp
                ${PROJECT_ROOT}/src/Player.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_ROOT}/include
                                                        ${PROJECT_ROOT}/include/gunHeaders)

set_target_cpp_standard(${PROJECT_NAME} 11)

enable_target_warnings(${PROJECT_NAME})