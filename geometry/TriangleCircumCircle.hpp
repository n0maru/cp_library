#pragma once
#include "template.hpp"
#include "CrossPointLL.hpp"

// 三角形(p0,p1,p2)の外接円
// O(1)
// 必要：crossPointLL
Circle circumCircle(Point p0, Point p1, Point p2) {
    Vec v01 = p1 - p0;
    Point a = (p0 + p1) * 0.5L;
    Line l1{a, a + Vec{v01.y, -v01.x}};
    Vec v12 = p2 - p1;
    Point b = (p1 + p2) * 0.5L;
    Line l2{b, b + Vec{v12.y, -v12.x}};
    Point cen = crossPointLL(l1, l2).first;
    ld r = (p0 - cen).abs();
    return Circle{cen, r};
}