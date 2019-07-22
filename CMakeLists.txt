cmake_minimum_required(VERSION 2.8.12)
project(sword_and_sorcery)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/textures.cpp)
# set(HEADERS include/textures.h)

add_library(tileset_glfw ${SOURCES})
set_target_properties(tileset_glfw PROPERTIES CXX_STANDARD 17)
target_link_libraries(tileset_glfw PUBLIC CONAN_PKG::glfw CONAN_PKG::ui-tileset)
target_link_libraries(tileset_glfw PRIVATE CONAN_PKG::stb)

target_include_directories(
    tileset_glfw PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
