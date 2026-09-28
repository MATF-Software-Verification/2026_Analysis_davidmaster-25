cmake_minimum_required(VERSION 3.10)
project(LibreSpriteIntegrationTests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include directories from LibreSprite
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../libre_sprite/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../libre_sprite/third_party
    ${CMAKE_CURRENT_SOURCE_DIR}/../libre_sprite/third_party/observable
)

# Integration Tests

# Point in Rect Tests
add_executable(test_point_in_rect test_point_in_rect.cpp)
target_link_libraries(test_point_in_rect GTest::GTest GTest::Main)
