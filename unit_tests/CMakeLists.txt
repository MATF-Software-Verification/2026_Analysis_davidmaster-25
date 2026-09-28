cmake_minimum_required(VERSION 3.10)
project(LibreSpriteUnitTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../libre_sprite/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../libre_sprite/third_party
    ${CMAKE_CURRENT_SOURCE_DIR}/../libre_sprite/third_party/observable
)

set(GFX_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../libre_sprite/src/gfx/rgb.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../libre_sprite/src/gfx/hsv.cpp
)

add_executable(test_color test_color.cpp ${GFX_SOURCES})
target_link_libraries(test_color GTest::GTest GTest::Main)

add_executable(test_rect test_rect.cpp)
target_link_libraries(test_rect GTest::GTest GTest::Main)

add_executable(test_point test_point.cpp)
target_link_libraries(test_point GTest::GTest GTest::Main)
