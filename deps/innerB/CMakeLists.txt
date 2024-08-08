cmake_minimum_required(VERSION 3.23)

project(InnerProjB LANGUAGES CXX)

add_library(InnerLibB STATIC)

target_compile_features(InnerLibB PUBLIC cxx_std_20)

target_sources(
    InnerLibB
    PUBLIC
        FILE_SET yk_inner_public_headers
        TYPE HEADERS
        BASE_DIRS include
        FILES include/innerB.hpp
    PRIVATE src/innerB.cpp
)

add_library(yk::InnerLibB ALIAS InnerLibB)

include(GNUInstallDirs)

install(
    TARGETS InnerLibB
    EXPORT InnerLibB-export
    FILE_SET yk_inner_public_headers DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT InnerLibB-export
    FILE InnerLibBTargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    NAMESPACE yk::
)
