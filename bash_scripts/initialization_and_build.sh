#!/bin/bash
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

# This script initializes a Git repository and adds LibreSprite as a submodule.
cd "$SCRIPT_DIR/.."
git init
git submodule add https://github.com/LibreSprite/LibreSprite.git ./libre_sprite
git submodule update --init --recursive
# Create a build directory for LibreSprite and run CMake to configure the build system.
mkdir -p ./build_libre_sprite
# Run CMake to generate the build system for LibreSprite.
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="--coverage" -S ./libre_sprite -B ./build_libre_sprite 
# Build LibreSprite using the generated build system.
cmake --build ./build_libre_sprite -j$(nproc)
