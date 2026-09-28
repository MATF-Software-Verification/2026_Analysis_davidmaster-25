#include <gtest/gtest.h>
#include "gfx/rect.h"
#include "gfx/point.h"

using namespace gfx;

TEST(PointInRectTest, Inside) {
    Rect rect(10, 10, 50, 50);
    Point pt(30, 30);
    EXPECT_TRUE(rect.contains(pt));
}

TEST(PointInRectTest, Origin) {
    Rect rect(10, 10, 50, 50);
    Point pt(10, 10);
    EXPECT_TRUE(rect.contains(pt));
}

TEST(PointInRectTest, BottomRightBoundary) {
    Rect rect(10, 10, 50, 50);
    Point pt(60, 60); // x+w = 60, y+h = 60
    EXPECT_FALSE(rect.contains(pt));
}

TEST(PointInRectTest, JustInsideBottomRight) {
    Rect rect(10, 10, 50, 50);
    Point pt(59, 59);
    EXPECT_TRUE(rect.contains(pt));
}

TEST(PointInRectTest, Outside) {
    Rect rect(10, 10, 50, 50);
    Point pt(0, 0);
    EXPECT_FALSE(rect.contains(pt));
    Point pt2(70, 70);
    EXPECT_FALSE(rect.contains(pt2));
}

TEST(PointInRectTest, OnTopEdge) {
    Rect rect(10, 10, 50, 50);
    Point pt(30, 10);
    EXPECT_TRUE(rect.contains(pt));
}

TEST(PointInRectTest, OnLeftEdge) {
    Rect rect(10, 10, 50, 50);
    Point pt(10, 30);
    EXPECT_TRUE(rect.contains(pt));
}

TEST(PointInRectTest, OnBottomEdge) {
    Rect rect(10, 10, 50, 50);
    Point pt(30, 60); // y+h = 60
    EXPECT_FALSE(rect.contains(pt));
}

TEST(PointInRectTest, OnRightEdge) {
    Rect rect(10, 10, 50, 50);
    Point pt(60, 30); // x+w = 60
    EXPECT_FALSE(rect.contains(pt));
}
