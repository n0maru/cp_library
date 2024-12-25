#pragma once
#include "template.hpp"

// 点pの直線l(p0,p1)への射影
// O(1)
Point proj(Line l, Point p) {
    auto [p1, p2] = l;
    ld r = dot(p2 - p1, p - p1) / (p2 - p1).norm2();
    return (p2 - p1) * r + p1;
}