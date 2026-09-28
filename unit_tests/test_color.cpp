#include <gtest/gtest.h>
#include "gfx/rgb.h"
#include "gfx/hsv.h"


using namespace gfx;


TEST(ColorTest, Constructor) {
    Rgb color(255, 0, 0);
    EXPECT_EQ(color.red(), 255);
    EXPECT_EQ(color.green(), 0);
    EXPECT_EQ(color.blue(), 0);

    Hsv color1(color);
    EXPECT_DOUBLE_EQ(color1.hue(), 0.0);
    EXPECT_DOUBLE_EQ(color1.saturation(), 1.0);
    EXPECT_DOUBLE_EQ(color1.value(), 1.0);

}

TEST(ColorTest, Equality) {
    Rgb color3(255, 0, 0);
    Rgb color4(255, 0, 0);
    Rgb color5(0, 255, 0);
    EXPECT_EQ(color3, color4);
    EXPECT_NE(color3, color5);

    Hsv hsv_color1(0, 1.0, 1.0);
    Hsv hsv_color2(0, 1.0, 1.0);
    Hsv hsv_color3(0.5, 0.5, 0.5);
    EXPECT_EQ(hsv_color1, hsv_color2);
    EXPECT_NE(hsv_color1, hsv_color3);
}

TEST(ColorTest, HsvConstructor) {
    Hsv hsv(0.0, 1.0, 1.0); // Red
    Rgb rgb(hsv);
    EXPECT_EQ(rgb.red(), 255);
    EXPECT_EQ(rgb.green(), 0);
    EXPECT_EQ(rgb.blue(), 0);
}

TEST(RgbTest, ConvertsHsvCases)
{
    {
        Rgb rgb(Hsv(60.0, 1.0, 1.0));

        EXPECT_EQ(rgb.red(), 255);
        EXPECT_EQ(rgb.green(), 255);
        EXPECT_EQ(rgb.blue(), 0);
    }

    {
        Rgb rgb(Hsv(120.0, 1.0, 1.0));

        EXPECT_EQ(rgb.red(), 0);
        EXPECT_EQ(rgb.green(), 255);
        EXPECT_EQ(rgb.blue(), 0);
    }

    {
        Rgb rgb(Hsv(180.0, 1.0, 1.0));

        EXPECT_EQ(rgb.red(), 0);
        EXPECT_EQ(rgb.green(), 255);
        EXPECT_EQ(rgb.blue(), 255);
    }

    {
        Rgb rgb(Hsv(240.0, 1.0, 1.0));

        EXPECT_EQ(rgb.red(), 0);
        EXPECT_EQ(rgb.green(), 0);
        EXPECT_EQ(rgb.blue(), 255);
    }

    {
        Rgb rgb(Hsv(300.0, 1.0, 1.0));

        EXPECT_EQ(rgb.red(), 255);
        EXPECT_EQ(rgb.green(), 0);
        EXPECT_EQ(rgb.blue(), 255);
    }

    {
        Rgb rgb(Hsv(360.0, 1.0, 1.0));

        EXPECT_EQ(rgb.red(), 255);
        EXPECT_EQ(rgb.green(), 0);
        EXPECT_EQ(rgb.blue(), 0);
    }
}

TEST(ColorTest, MinMaxComponent) {
    Rgb color6(10, 50, 100);
    EXPECT_EQ(color6.maxComponent(), 100);
    EXPECT_EQ(color6.minComponent(), 10);

    Rgb color7(255, 255, 255);
    EXPECT_EQ(color7.maxComponent(), 255);
    EXPECT_EQ(color7.minComponent(), 255);

    Rgb color8(0, 0, 0);
    EXPECT_EQ(color8.maxComponent(), 0);
    EXPECT_EQ(color8.minComponent(), 0);
}
