#pragma once
#include "template.hpp"

// 直線と直線の交点
// 交わることがわかっているなら線分と直線の交点も求めることができる
// O(1)
// returns.second: 0...交点がない
// returns.second: 1...交点が1つある
// returns.second: 2...交点が無限個ある
pair<Point,int> crossPointLL(Line a, Line b) {
    Vec v1 = a.second - a.first;
    Vec v2 = b.second - b.first;
    Vec v = b.first - a.first;
    // 平行
    if (sgn(crs(v1, v2)) == 0) {
        Vec v3 = b.second - a.second;
        // 交点が無限個存在する
        if (sgn(crs(v1, v3)) == 0) {
            return {Point(), 2};
        } else {
            return {Point(), 0};
        }
    }
    ld t = crs(v, v1) / crs(v1, v2);
    Point p = b.first + t * v2;
    return {p, 1};
}