#pragma once
#include "template.hpp"

// 線分同士の交差判定
// O(1)
bool isIntersectSS(Seg s1, Seg s2) {
    auto [a,b] = s1;
    auto [c,d] = s2;
    return (isp(a,b,c) * isp(a,b,d) <= 0 && isp(c,d,a) * isp(c,d,b) <= 0);
}