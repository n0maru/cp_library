#pragma once
#include "vec.hpp"
// 型
using ld = long double;
using Vec = vec<ld>;
using Point = vec<ld>;
using Seg = pair<Point, Point>;
using Line = Seg;
struct Circle {
    Point center;
    ld radius;
};
using Polygon = vector<Point>;

#define EPS ld(1e-10)
int sgn(ld val) {
    return (val < -EPS ? -1 : (val > EPS ? 1 : 0));
}
// 内積
ld dot(Vec a, Vec b) {
    return a.x * b.x + a.y * b.y;
}
// 外積
ld crs(Vec a, Vec b) {
    return a.x * b.y - a.y * b.x;
}
// 点の進行方向
#define CCW (1)
#define CW (-1)
#define OLB (2)
#define OLF (-2)
#define OS (0)
int isp(Point p0, Point p1, Point p2) {
    Vec a = p1 - p0;
    Vec b = p2 - p0;
    int val = sgn(crs(a,b));
    if (val > 0) return CCW;
    if (val < 0) return CW;
    if (sgn(dot(a,b)) < 0) return OLB;
    if (sgn(a.norm2() - b.norm2()) < 0) return OLF;
    return OS;
}