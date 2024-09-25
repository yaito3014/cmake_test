cmake_minimum_required(VERSION 3.23)

project(InnerProjA LANGUAGES CXX)

add_library(InnerLibA INTERFACE)

target_compile_features(InnerLibA INTERFACE cxx_std_20)

target_sources(
    InnerLibA
    INTERFACE FILE_SET HEADERS BASE_DIRS include FILES include/innerA.hpp
)

add_library(yk::InnerLibA ALIAS InnerLibA)

include(GNUInstallDirs)

install(
    TARGETS InnerLibA
    EXPORT InnerLibATargets
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

export(
    EXPORT InnerLibATargets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/InnerLibAConfig.cmake
)

install(
    EXPORT InnerLibATargets
    FILE InnerLibATargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    NAMESPACE yk::
)
