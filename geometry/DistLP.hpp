#pragma once
#include "template.hpp"

// 直線と点の距離
// O(1)
ld distLP(Line l, Point p) {
    auto [a,b] = l;
    return abs(crs(b-a, p-a)) / (b-a).abs();
}