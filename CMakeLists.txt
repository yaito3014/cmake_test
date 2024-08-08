cmake_minimum_required(VERSION 3.23)

project(OuterProj VERSION 0.0.1 LANGUAGES CXX)

add_library(OuterLib STATIC)

target_compile_features(OuterLib PUBLIC cxx_std_20)

target_sources(
    OuterLib
    PUBLIC
        FILE_SET yk_outer_public_headers
        TYPE HEADERS
        BASE_DIRS include
        FILES include/outer.hpp
    PRIVATE
        FILE_SET yk_outer_private_headers
        TYPE HEADERS
        FILES src/outer_impl.hpp
    PRIVATE src/outer.cpp
)

add_subdirectory(deps/innerA)
add_subdirectory(deps/innerB)

target_link_libraries(OuterLib PUBLIC yk::InnerLibA)
target_link_libraries(OuterLib PUBLIC yk::InnerLibB)

add_library(yk::OuterLib ALIAS OuterLib)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/OuterLibConfigVersion.cmake
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    cmake/OuterLibConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/OuterLibConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

install(
    TARGETS OuterLib
    EXPORT OuterLib-export
    FILE_SET yk_outer_public_headers DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT OuterLib-export
    FILE OuterLibTargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    NAMESPACE yk::
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/OuterLibConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/OuterLibConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)
