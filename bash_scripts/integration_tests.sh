#!/bin/bash
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
TEST_DIR="$SCRIPT_DIR/../integration_tests"
BUILD_DIR="$TEST_DIR/build"

mkdir -p "$BUILD_DIR"

cd "$BUILD_DIR"
echo "====================================================================="
cmake -DCMAKE_CXX_FLAGS="--coverage" -DCMAKE_EXE_LINKER_FLAGS="--coverage" ..

echo "====================================================================="
cmake --build .

echo "====================================================================="
./test_point_in_rect

echo "====================================================================="
lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch
lcov --remove coverage.info '*/CMakeFiles/*' '*/test_*.cpp' '*/gtest/*' '/usr/include/*' -o coverage_filtered.info
genhtml coverage_filtered.info --output-directory coverage_report

echo "====================================================================="
