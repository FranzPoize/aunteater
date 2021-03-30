cmake_minimum_required(VERSION 3.15)

# Setting the VERSION on root project() will populate CMAKE_PROJECT_VERSION
# see: https://cmake.org/cmake/help/v3.13/variable/CMAKE_PROJECT_VERSION.html
project(Aunteater VERSION "${BUILD_VERSION}")

# Setup cmake helpers in 'cmake' submodule
include(cmake/include.cmake)


##
## Build options
##

# Common build settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(LINK_OPTIONS "/INCREMENTAL:NO")
endif()

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()


##
## Include components
##

include(cmc-install)
cmc_install_root_component_config()

add_subdirectory(src)
