#!/bin/bash
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
SOURCE_DIR="$SCRIPT_DIR/../libre_sprite/src/app/"
OUTPUT_DIR="$SCRIPT_DIR/../cppcheck_static"

mkdir -p "$OUTPUT_DIR"

cppcheck --enable=all --inconclusive --xml --xml-version=2 "$SOURCE_DIR" 2> "$OUTPUT_DIR/deep_analysis.xml"


echo "=====================================================================" 
echo "  ANALIZA ZAVRSENA!"
echo "  Rezultati su sacuvani u folderu: $OUTPUT_DIR"
echo "=====================================================================" 
python "$OUTPUT_DIR/parser.py" "$OUTPUT_DIR/deep_analysis.xml" "$OUTPUT_DIR/analysis_report.html"
