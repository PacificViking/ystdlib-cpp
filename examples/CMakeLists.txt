cmake_minimum_required(VERSION 3.22.1)

project(ystdlib-examples)

if(ystdlib-examples_IS_TOP_LEVEL)
    message("${CMAKE_SOURCE_DIR}/../build/deps/cmake-settings/settings.cmake")
    include("${CMAKE_SOURCE_DIR}/../build/deps/cmake-settings/settings.cmake" OPTIONAL)
endif()

if(NOT DEFINED ystdlib_ROOT)
    set(ystdlib_ROOT "${CMAKE_SOURCE_DIR}/../build/build_install")
endif()
find_package(ystdlib REQUIRED)

add_library(
    common
    OBJECT
    types.cpp
    types.hpp
    constants.hpp
)
target_link_libraries(common PRIVATE ystdlib::error_handling)
add_executable(main main.cpp)

target_compile_features(main PRIVATE cxx_std_20)
target_compile_features(common PRIVATE cxx_std_20)

target_link_libraries(
    main
    PUBLIC
        ystdlib::error_handling
        common
)
