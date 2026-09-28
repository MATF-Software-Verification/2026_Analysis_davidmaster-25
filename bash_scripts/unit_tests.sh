#!/bin/bash
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
mkdir -p "$SCRIPT_DIR/../unit_tests/build"
cd "$SCRIPT_DIR/../unit_tests/build"

cmake -DCMAKE_CXX_FLAGS="--coverage" -DCMAKE_EXE_LINKER_FLAGS="--coverage" ..

cmake --build .

./test_color && ./test_rect && ./test_point

lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch
lcov --remove coverage.info '*/CMakeFiles/*' '*/test_*.cpp' '*/gtest/*' '/usr/include/*' -o coverage_filtered.info
genhtml coverage_filtered.info --output-directory ./coverage_report

