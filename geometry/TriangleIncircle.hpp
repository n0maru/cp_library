#pragma once
#include "template.hpp"

// 三角形(p0,p1,p2)の内接円
// O(1)
Circle incircle(Point p0, Point p1, Point p2) {
    ld l = (p0-p1).abs() + (p1-p2).abs() + (p2-p0).abs();
    Point cen = (p1-p2).abs() * p0 + (p0-p2).abs() * p1 + (p0-p1).abs() * p2;
    cen /= l;
    ld r = abs(crs(p1-p0, p2-p0)) / l;
    return Circle{cen, r};
}