cmake_minimum_required(VERSION 3.20)

project(AirConflicts.WidescreenFix)

set(CMAKE_CXX_STANDARD 20)

add_library(AirConflicts.WidescreenFix SHARED
    src/dllmain.cpp
)

target_compile_definitions(AirConflicts.WidescreenFix PRIVATE
    WIN32_LEAN_AND_MEAN
)