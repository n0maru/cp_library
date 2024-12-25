#pragma once
#include "template.hpp"

// 円と円の交点
// O(1)
ld arg(Vec p) { return atan2(p.y, p.x); }
Vec polar(ld a, ld r) { return Point(cos(r) * a, sin(r) * a); }
vector<Point> crossPointCC(Circle c1, Circle c2) {
    auto [cen1, r1] = c1;
    auto [cen2, r2] = c2;
    if (sgn((cen1 - cen2).abs() - (r1 + r2)) > 0) {
        return vector<Point>();
    }
    ld d = (cen1 - cen2).abs();
    ld a = acos((r1*r1 + d*d - r2*r2) / (2*r1*d));
    ld t = arg(cen2 - cen1);
    if (a == 0) {
        return { cen1 + polar(r1, t) };
    } else {
        return { cen1 + polar(r1, t+a), cen1 + polar(r1, t-a) };
    }
}