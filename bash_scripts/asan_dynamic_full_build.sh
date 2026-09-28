#!/bin/bash
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

# Ne prolazi build, previse curenja memorije
SOURCE_DIR="$SCRIPT_DIR/.."

mkdir -p "$SOURCE_DIR/build_libre_sprite_asan"
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=address -fno-omit-frame-pointer" -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address" -S "$SOURCE_DIR/libre_sprite" -B "$SOURCE_DIR/build_libre_sprite_asan"
cmake --build "$SOURCE_DIR/build_libre_sprite_asan" -j$(nproc)
