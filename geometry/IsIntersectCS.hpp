#pragma once
#include "template.hpp"
#include "DistPS.hpp"

// 円と線分の交差判定
// O(1)
// 必要：distPS
bool isIntersectCS(Circle c, Seg s) {
    auto [p1, p2] = s;
    auto [cen, r] = c;
    // 線分が内包されているならfalse
    if (sgn((p1 - cen).abs() - r) <= 0 && sgn((p2 - cen).abs()) - r <= 0) return false;

    return (sgn(distPS(cen, s) - r) <= 0);
}