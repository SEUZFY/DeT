cmake_minimum_required (VERSION 3.8)

project ("DeT")

#set C++ standard
set (CMAKE_CXX_STANDARD 11)

#include subprojects
add_subdirectory("glfw")
add_subdirectory("glew")

add_executable (DeT  "src/Geometry.hpp" "src/main.cpp")

#specify include directories
target_include_directories(DeT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)
target_include_directories(DeT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glew/include)

#link the libraries
target_link_libraries(DeT glfw libglew_static)

