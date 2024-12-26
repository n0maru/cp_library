#pragma once
#include "template.hpp"
// 線分と点の距離
// O(1)
ld distPS(Point p, Seg s) {
    auto [a,b] = s;
    if (sgn(dot(b-a, p-a)) < 0) return (p - a).abs();
    if (sgn(dot(a-b, p-b)) < 0) return (p - b).abs();
    return abs(crs(b-a,p-a)) / (b-a).abs();
}