#pragma once
#include "template.hpp"

// 円c0と円c1の共通部分の面積
// O(1)
ld intersectionAreaCC(Circle c0, Circle c1) {
    auto [cen0, r0] = c0;
    auto [cen1, r1] = c1;
    ld d = (cen0 - cen1).abs();
    if (sgn(d - (r0 + r1)) >= 0) return 0.0L;
    if (sgn(d - abs(r0 - r1)) <= 0) {
        return acos(-1) * min(r0,r1) * min(r0,r1);
    }
    ld p0 = (r0*r0 - r1*r1 + d*d);
    ld p1 = (r1*r1 - r0*r0 + d*d);

    ld s1 = r0*r0 * atan2(sqrtl(4*d*d*r0*r0 - p0*p0), p0);
    ld s2 = r1*r1 * atan2(sqrtl(4*d*d*r1*r1 - p1*p1), p1);
    ld s0 = sqrtl(4*d*d*r0*r0 - p0*p0) / 2.0L;
    return s1 + s2 - s0;
}