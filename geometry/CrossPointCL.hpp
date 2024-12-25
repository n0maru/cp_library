#pragma once
#include "template.hpp"
#include "Projection.hpp"
#include "DistLP.hpp"
// 円と直線の交点
// 交点は 0 or 1 or 2 個
// O(1)
// 必要：proj, distLP
vector<Point> crossPointCL(Circle c, Line l) {
    auto [cen,r] = c;
    auto [a,b] = l;
    if (sgn(distLP(l,cen) - r) > 0) {
        return vector<Point>();
    }
    Point prj = proj(l, cen);
    Vec e = (b-a) / (b-a).abs();
    ld d = sqrtl(r*r - (prj - cen).norm2());
    vector<Point> res;
    res.push_back(prj + e * d);
    if (sgn(d) != 0) res.push_back(prj - e * d);
    return res;
}