cmake_minimum_required(VERSION 2.8.12)
project(sword_and_sorcery)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/textures.cpp)
file(GLOB HEADERS include/tileset/*)

add_library(tileset_glfw ${SOURCES} ${HEADERS})
set_target_properties(tileset_glfw PROPERTIES CXX_STANDARD 17)
target_link_libraries(tileset_glfw PUBLIC CONAN_PKG::glfw CONAN_PKG::ui-tileset)
target_link_libraries(tileset_glfw PRIVATE CONAN_PKG::stb)

target_include_directories(
    tileset_glfw PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS tileset_glfw
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/tileset_glfw
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ)
