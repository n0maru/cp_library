#pragma once
#include "template.hpp"
#include "IsIntersectSS.hpp"

// 線分と線分の交点
// O(1)
// returns.second: 0...交点がない
// returns.second: 1...交点が1つある
// returns.second: 2...交点が無限個ある
// 必要：isIntersectSS(Seg,Seg)
pair<Point,int> crossPointSS(Seg s1, Seg s2) {
    // have cross point
    if (!isIntersectSS(s1, s2)) {
        return {Point(), 0};
    }
    //not parallel
    if (sgn(crs(Vec(s1.second - s1.first), Vec(s2.second - s2.first))) == 0) {
        return {Point(), 2};
    }
    auto [a,b] = s1;
    auto [c,d] = s2;
    ld d1 = abs(crs(b-a, c-a));
    ld d2 = abs(crs(b-a, d-a));
    return {c + (d-c) * d1 / (d1 + d2), 1};
}