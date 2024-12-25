#pragma once
#include "template.hpp"
#include "distPS.hpp"
#include "IsIntersectCS.hpp"
#include "CrossPointCS.hpp"

// 円cと多角形pの共通部分の面積
// O(1)
// 必要：distPS, isIntersectCS, crossPointCS
ld arg(Point p0, Point p1) {
    return atan2(crs(p0, p1), dot(p0, p1));
}
ld interctionArea(Circle c, Polygon p) {
    auto [cen, r] = c;
    ld area = 0.0L;
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        Point p0 = p[i] - cen, p1 = p[(i + 1) % n] - cen;
        if (abs(isp(cen, p0, p1)) != 1) continue;

        // 円に内包された三角形
        if (sgn(abs(p0) - r) < 0 && sgn(abs(p1) - r) < 0) {
            area += crs(p0, p1) / 2.0L;
        }
        // 三角形と扇形ひとつ(p0側)
        else if (sgn(abs(p0) - r) < 0) { 
            auto ps = crossPointCS(c, Seg{ p0, p1 });
            assert(ps.size() == 1);
            area += crs(p0, ps.front()) / 2.0L;
            area += r * r * arg(ps.front(), p1) / 2.0L;
        }
        // 三角形と扇形ひとつ(p1側)
        else if (sgn(abs(p1) - r) < 0) {
            auto ps = crossPointCS(c, Seg{ p0, p1 });
            assert(ps.size() == 1);
            area += crs(ps.front(), p1) / 2.0L;
            area += r * r * arg(p0, ps.front()) / 2.0L;
        } else {
            auto ps = crossPointCS(c, Seg{p0, p1});
            if (ps.size() == 0) { // 扇形一つ
                area += r * r * arg(p0, p1) / 2.0L;
            } else { // 三角形と扇形ふたつ
                area += r * r * arg(p0, ps.front()) / 2.0L;
                area += r * r * arg(ps.back(), p1) / 2.0L;
                area += crs(ps.front(), ps.back()) / 2.0L;
            }
        }
    }
    return area;
}
