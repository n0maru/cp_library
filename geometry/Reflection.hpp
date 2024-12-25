#pragma once
#include "template.hpp"
#include "Projection.hpp"

// 点pの直線lに対して対象な点を求める
// O(1)
// 必要：proj
Point refl(Line l, Point p) {
    Point prj = proj(l, p);
    return (prj - p) * 2.0L + p;
}