cmake_minimum_required(VERSION 3.10)
project(LibreSpriteUnitTests)

# 1. Postavljanje putanje do LibreSprite-a
set(LIBRE_SPRITE_DIR /home/uno/Desktop/master/VerifikacijaSoftvera/Projekat/libre_sprite)

# 2. Traženje GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

# 3. VAŽNO: Traženje SDL2 biblioteka (Ovo je popravilo tvoju grešku)
find_package(SDL2 REQUIRED)
# Neke verzije SDL2 na Fedori koriste drugačije nazive targeta, 
# pa ćemo osigurati da ih pronađemo.
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

# 4. Dodavanje Include putanja
include_directories(
    ${LIBRE_SPRITE_DIR}
    ${LIBRE_SPRITE_DIR}/doc
    ${LIBRE_SPRITE_DIR}/gfx
    ${LIBRE_SPRITE_DIR}/common
    ${LIBRE_SPRITE_DIR}/util
    ${SDL2_INCLUDE_DIRS}  # Dodajemo i SDL2 putanje
)

# 5. Defisanje izvornih fajlova
file(GLOB_RECURSE LIBRE_SRC_FILES
    "${LIBRE_SPRITE_DIR}/doc/brush.cpp"
    "${LIBRE_SPRITE_DIR}/doc/brush.h"
    "${LIBRE_SPRITE_DIR}/doc/image.cpp"
    "${LIBRE_SPRITE_DIR}/gfx/point.cpp"
    "${LIBRE_SPRITE_DIR}/gfx/rect.cpp"
    "${LIBRE_SPRITE_DIR}/gfx/color.cpp"      # Često je boja u posebnom fajlu
    "${LIBRE_SPRITE_DIR}/doc/image_color.cpp" # Ako postoji zasebno
)

# 6. Kreiranje izvršnog fajla
add_executable(BrushTest_exe /home/uno/Desktop/master/VerifikacijaSoftvera/Projekat/asan_dynamic/test_brush.cpp  ${LIBRE_SRC_FILES})

# 7. Linkovanje
# Koristićemo varijable koje find_package popuni, jer su sigurnije od "::" targeta na nekim sistemima
target_link_libraries(BrushTest_exe 
    GTest::GTest 
    GTest::Main
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
)

# Ako i dalje budeš imao "undefined reference", 
# probaj da dodaš i direktno linkovanje sa tvojim build-ovanim lib-om:
# target_link_libraries(BrushTest_exe ${LIBRE_SPRITE_DIR}/build/liblibresprite.a)