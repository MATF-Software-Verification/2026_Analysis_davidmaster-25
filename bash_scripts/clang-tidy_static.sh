#!/bin/bash

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR/.."
BUILD_DIR="$PROJECT_ROOT/build_libre_sprite"
CONFIG_FILE="$PROJECT_ROOT/clang-tidy_static/.clang-tidy"
TARGET_DIR="$PROJECT_ROOT/libre_sprite/src/app/modules"
OUTPUT_FILE="$PROJECT_ROOT/clang-tidy_static/clang_tidy_results.txt"
echo "Staticka analiza koda uz pomoc alata clang-tidy na putanji: $TARGET_DIR"
if [ ! -f "$BUILD_DIR/compile_commands.json" ]; then
    echo "Greska: compile_commands.json se ne nalazi u folderu $BUILD_DIR"
    echo "Pokreni: cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S $PROJECT_ROOT/libre_sprite -B $PROJECT_ROOT/build_libre_sprite"
    exit 1
fi

find "$TARGET_DIR" -name "*.cpp" -o -name "*.h" | xargs clang-tidy \
    -p "$BUILD_DIR" \
    --config-file="$CONFIG_FILE" > "$OUTPUT_FILE" 2>&1
echo "===================================================="
echo "  ANALIZA ZAVRSENA!"
echo "  Rezultati su sacuvani u folderu: $OUTPUT_FILE"
echo "=====================================================================" 
echo "Kategorija [modernize.*] ukupno:"
grep -E '\[modernize.*\]' "$OUTPUT_FILE" | wc -l 
echo "=====================================================================" 
echo "Kategorija [bugprone.*] ukupno:"
grep -E '\[bugprone.*\]' "$OUTPUT_FILE" | wc -l 
echo "=====================================================================" 
echo "Kategorija [google.*] ukupno:" 
grep -E '\[google.*\]' "$OUTPUT_FILE" | wc -l 
echo "=====================================================================" 
echo "Kategorija [readability.*] ukupno:"
grep -E '\[readability.*\]' "$OUTPUT_FILE" | wc -l 
echo "====================================================================="  
echo "Kategorija [cppcoreguidelines.*] ukupno:"
grep -E '\[cppcoreguidelines.*\]' "$OUTPUT_FILE" | wc -l 
echo "=====================================================================" 
