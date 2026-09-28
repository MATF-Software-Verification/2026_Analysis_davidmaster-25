#include <gtest/gtest.h>
#include "gfx/rect.h"
#include "gfx/point.h"

TEST(RectTest, Constructor) {
    gfx::Rect rect(10, 20, 30, 40);
    EXPECT_EQ(rect.x, 10);
    EXPECT_EQ(rect.y, 20);
    EXPECT_EQ(rect.w, 30);
    EXPECT_EQ(rect.h, 40);
}

TEST(RectTest, Empty) {
    gfx::Rect rect;
    EXPECT_TRUE(rect.isEmpty());
    EXPECT_EQ(rect.x, 0);
    EXPECT_EQ(rect.y, 0);
    EXPECT_EQ(rect.w, 0);
    EXPECT_EQ(rect.h, 0);
}

TEST(RectTest, Equality) {
    gfx::Rect rect1(10, 20, 30, 40);
    gfx::Rect rect2(10, 20, 30, 40);
    gfx::Rect rect3(0, 0, 0, 0);
    EXPECT_EQ(rect1, rect2);
    EXPECT_NE(rect1, rect3);
}

TEST(RectTest, Contains) {
    gfx::Rect rect(0, 0, 100, 100);
    gfx::Point pt1(50, 50);
    gfx::Point pt2(150, 150);
    gfx::Point pt3(0, 0);
    gfx::Point pt4(100, 100);

    EXPECT_TRUE(rect.contains(pt1));
    EXPECT_TRUE(rect.contains(pt3));
    EXPECT_FALSE(rect.contains(pt2));
    EXPECT_FALSE(rect.contains(pt4));
}

TEST(RectTest, Intersects) {
    gfx::Rect rect1(0, 0, 100, 100);
    gfx::Rect rect2(50, 50, 100, 100);
    gfx::Rect rect3(150, 150, 10, 10);
    gfx::Rect rect4(100, 100, 10, 10);

    EXPECT_TRUE(rect1.intersects(rect2));
    EXPECT_FALSE(rect1.intersects(rect3));
    EXPECT_FALSE(rect1.intersects(rect4));
}
