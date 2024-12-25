#pragma once
#include "template.hpp"
#include "IsIntersectSS.hpp"
#include "DistPS.hpp"

// 線分と線分の距離
// O(1)
// 必要：isIntersect(Seg,Seg), distSP
ld distSS(Seg s1, Seg s2) {
    if (isIntersectSS(s1, s2)) return 0.0L;
    auto [a,b] = s1;
    auto [c,d] = s2;
    return min(
        min(distPS(a,s2), distPS(b,s2)),
        min(distPS(c,s1), distPS(d,s1))
    );
}