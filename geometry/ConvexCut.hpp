#pragma once
#include "template.hpp"
#include "CrossPointLL.hpp"

// 直線で切った左側の凸多角形を求める
// 直線で切られない場合、元の凸多角形または空を返す（はず）
// 必要：crossPointLL
Polygon convexCut(Polygon g, Line l) {
    auto [p0, p1] = l;
    int n = g.size();
    Polygon p;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if (isp(p0, p1, g[i]) != CW) p.push_back(g[i]);
        if (isp(p0, p1, g[i]) * isp(p0, p1, g[j]) == -1) {
            p.push_back(crossPointLL(Line{p0, p1}, Line{g[i], g[j]}).first);
        }
    }
    return p;
}