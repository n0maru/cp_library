#pragma once
#include "template.hpp"
#include "CrossPointCC.hpp"

// 点pを通り円cに接する直線と円cとの交点
// O(1)
// 必要：crossPointCC(Circle, Circle)
vector<Point> tangentPoints(Point p, Circle c) {
    ld r = c.radius;
    ld y = sqrtl((c.center - p).norm2() - r*r);
    Circle tgt{p, y};
    return crossPointCC(c, tgt);
}