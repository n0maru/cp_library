#pragma once
#include "template.hpp"

// 凸包な多角形の頂点間の最大距離
// O(n)
ld diameter(Polygon p) {
    int n = (int)p.size();
    int midx=0, maidx=0;
    for (int i = 0; i < n; ++i) {
        if (p[i].y > p[maidx].y) maidx = i;
        if (p[i].y < p[midx].x) midx = i;
    }
    ld maxdis = 0;
    for (int i=0, j=0; i < n; ++i) {
        ld now = (p[i] - p[j]).abs();
        while (j+1 < n) {
            ld next = (p[i] - p[j+1]).abs();
            if (next > now) {
                now = next;
                ++j;
            } else {
                break;
            }
        }
        if (now > maxdis) {
            maxdis = now;
        }
    }
    return maxdis;
}