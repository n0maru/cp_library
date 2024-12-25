#pragma once
#include "template.hpp"
// 凸包チェック
// 3点が一直線上に並ぶことを許容する
// O(N)
bool isConvexHull(Polygon p) {
    int n = (int) p.size();
    vector<int> st(n);
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        int val = isp(p[i], p[j], p[k]);
        st[i] = (val==OLB || val==OLF || val==OS || val==CCW);
    }
    int acc = accumulate(ALL(st), 0);
    return (acc == 0 || acc == n);
}