cmake_minimum_required(VERSION 3.5.1)

project(warcraft)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
                ${PROJECT_ROOT}/src/heroSrc/Archmage.cpp
                ${PROJECT_ROOT}/src/heroSrc/DeathKnight.cpp
                ${PROJECT_ROOT}/src/heroSrc/DrawRanger.cpp
                ${PROJECT_ROOT}/src/Spell.cpp
                ${PROJECT_ROOT}/src/heroSrc/Hero.cpp
                ${PROJECT_ROOT}/src/Casting.cpp
                ${PROJECT_ROOT}/src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_ROOT}/include 
                                                    ${PROJECT_ROOT}/include/heroHeaders)
                                                    

set_target_cpp_standard(${PROJECT_NAME} 11)

enable_target_warnings(${PROJECT_NAME})