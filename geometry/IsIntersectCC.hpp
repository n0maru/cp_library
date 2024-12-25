#pragma once
#include "template.hpp"

// 円同士の交差判定
// O(1)
#define NOT_CROSS (4) // 離れている（共通の接線：４本）
#define CIRCUMSCRIBE (3) // 外接する（共通の接線：３本）
#define INTERSECT (2) // 交わる（共通の接線：２本）
#define INSCRIBE (1) // 内接する（共通の接線：１本）
#define INCLUDE (0) // 内包する（共通の接線：０本）
int isIntersectCC(Circle c1, Circle c2) {
    if (c1.radius < c2.radius) swap(c1, c2);
    ld dist = (c1.center - c2.center).abs();
    int ds = sgn(dist - (c1.radius + c2.radius));
    if (ds > 0) {
        return NOT_CROSS;
    } else if (ds == 0) {
        return CIRCUMSCRIBE;
    } else {
        ld maxDist = (c1.center - c2.center).abs() + c2.radius;
        int val = sgn(maxDist - c1.radius);
        if (val > 0) {
            return INTERSECT;
        } else if (val == 0) {
            return INSCRIBE;
        } else {
            return INCLUDE;
        }
    }
    assert(false);
    return NOT_CROSS;
}