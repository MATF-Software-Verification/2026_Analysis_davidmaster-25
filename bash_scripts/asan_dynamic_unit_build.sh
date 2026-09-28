#!/bin/bash
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

mkdir "$SCRIPT_DIR/asan_dynamic/build"

cmake  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=address -fno-omit-frame-pointer" -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address" -S /home/uno/Desktop/master/VerifikacijaSoftvera/Projekat/asan_dynamic -B /home/uno/Desktop/master/VerifikacijaSoftvera/Projekat/asan_dynamic/build
cmake --build /home/uno/Desktop/master/VerifikacijaSoftvera/Projekat/asan_dynamic/build -j$(nproc)

