cmake_minimum_required(VERSION 3.25)

project(
  advent-of-code-2015
  VERSION 1.0.0
  LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(lib)
add_subdirectory(day01)
add_subdirectory(day02)
add_subdirectory(day03)
