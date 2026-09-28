#include <gtest/gtest.h>
#include "gfx/point.h"

TEST(PointTest, Constructor) {
    gfx::Point pt(10, 20);
    EXPECT_EQ(pt.x, 10);
    EXPECT_EQ(pt.y, 20);
}

TEST(PointTest, Equality) {
    gfx::Point pt1(10, 20);
    gfx::Point pt2(10, 20);
    gfx::Point pt3(20, 10);
    EXPECT_EQ(pt1, pt2);
    EXPECT_NE(pt1, pt3);
}

TEST(PointTest, Operators) {
    gfx::Point pt1(10, 20);
    gfx::Point pt2(5, 5);
    
    gfx::Point pt3 = pt1 + pt2;
    EXPECT_EQ(pt3.x, 15);
    EXPECT_EQ(pt3.y, 25);

    gfx::Point pt4 = pt1 - pt2;
    EXPECT_EQ(pt4.x, 5);
    EXPECT_EQ(pt4.y, 15);

    pt1 += pt2;
    EXPECT_EQ(pt1.x, 15);
    EXPECT_EQ(pt1.y, 25);

    pt1 -= 5;
    EXPECT_EQ(pt1.x, 10);
    EXPECT_EQ(pt1.y, 20);
}
