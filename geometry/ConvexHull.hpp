#pragma once
#include "template.hpp"

// 多角形pの凸包をもとめる
// 頂点は反時計回り（CCW）に並べられている
// 凸包の辺上の点も含める場合は!=CWを==CCWに置き換える
// O(NlogN)
Polygon convexHull(Polygon p) {
    if (p.size() < 3) return p;
    sort(ALL(p), [](Point a, Point b) {
        return (sgn(a.x - b.x) != 0 ? a.x < b.x : a.y < b.y);
    });
    // 上部
    Polygon u;
    u.push_back(p[0]);
    u.push_back(p[1]);
    for (int i = 2; i < p.size(); ++i) {
        for (int n = u.size(); n >= 2 && isp(u[n-2], u[n-1], p[i]) == CCW; --n) {
            u.pop_back();
        }
        u.push_back(p[i]);
    }
    // 下部
    Polygon l;
    l.push_back(p[p.size() - 1]);
    l.push_back(p[p.size() - 2]);
    for (int i = p.size()-3; i >= 0; --i) {
        for (int n = l.size(); n >= 2 && isp(l[n-2], l[n-1], p[i]) == CCW; --n) {
            l.pop_back();
        }
        l.push_back(p[i]);
    }
    reverse(ALL(l));
    for (int i = u.size() - 2; i >= 1; --i) l.push_back(u[i]);
    return l;
}