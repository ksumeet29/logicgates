cmake_minimum_required(VERSION 4.1)
project(LogicGates LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library bundling all gate implementations
add_library(gates
  src/gates.cpp
)
target_include_directories(gates PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Main executable links against the gates library
add_executable(logicgate src/main.cpp)
target_link_libraries(logicgate PRIVATE gates)