#!/bin/bash
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
SOURCE_DIR="$SCRIPT_DIR/../build_libre_sprite/bin"
OUTPUT_DIR="$SCRIPT_DIR/../valgrind-massif"

valgrind --tool=massif --massif-out-file="$OUTPUT_DIR/massif.out" "$SOURCE_DIR/libresprite"
