cmake_minimum_required(VERSION 3.5.1)

project(starcraft)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Starcraft
                ${PROJECT_ROOT}/src/BattleCruser.cpp
                ${PROJECT_ROOT}/src/BattleField.cpp
                ${PROJECT_ROOT}/src/Carrier.cpp
                ${PROJECT_ROOT}/src/main.cpp
                ${PROJECT_ROOT}/src/Phoenix.cpp
                ${PROJECT_ROOT}/src/ProtosFleet.cpp
                ${PROJECT_ROOT}/src/TerranFleet.cpp
                ${PROJECT_ROOT}/src/Viking.cpp
)

target_include_directories(Starcraft PRIVATE ${PROJECT_ROOT}/include)