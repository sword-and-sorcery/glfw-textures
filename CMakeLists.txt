cmake_minimum_required(VERSION 2.8.12)
project(sword_and_sorcery)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/textures.cpp)
# set(HEADERS include/textures.h)

add_library(glfw_tileset ${SOURCES})
set_target_properties(glfw_tileset PROPERTIES CXX_STANDARD 17)
target_link_libraries(glfw_tileset PUBLIC CONAN_PKG::glfw CONAN_PKG::tileset CONAN_PKG::stb)

target_include_directories(
    glfw_tileset PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(
    TARGETS glfw_tileset
    EXPORT glfw_tileset-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    EXPORT glfw_tileset-config
    NAMESPACE glfw_tileset::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/glfw_tileset)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glfw_tileset)
