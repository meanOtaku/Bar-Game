cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0)

INCLUDE_DIRECTORIES(
    "<path to vcpkg>/vcpkg/installed/x64-windows/include"
)
LINK_DIRECTORIES(
    "<path to vcpkg>/vcpkg/installed/x64-windows/lib"
)

include(CTest)
enable_testing()

add_executable(game main.cpp)

TARGET_LINK_LIBRARIES(game
    raylib
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
