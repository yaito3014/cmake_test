cmake_minimum_required(VERSION 3.23)

project(InnerProjB LANGUAGES CXX)

add_library(InnerLibB STATIC)

target_compile_features(InnerLibB PUBLIC cxx_std_20)

target_sources(
    InnerLibB
    PUBLIC FILE_SET HEADERS BASE_DIRS include FILES include/innerB.hpp
    PRIVATE src/innerB.cpp
)

add_library(yk::InnerLibB ALIAS InnerLibB)

include(GNUInstallDirs)

install(
    TARGETS InnerLibB
    EXPORT InnerLibBTargets
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

export(
    EXPORT InnerLibBTargets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/InnerLibBConfig.cmake
)

install(
    EXPORT InnerLibBTargets
    FILE InnerLibBTargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    NAMESPACE yk::
)
