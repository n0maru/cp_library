#pragma once
#include "template.hpp"

// 自己交差の無い多角形の面積
// O(n)
ld area(Polygon p) {
    ld sum = 0;
    for (int i = 0; i < p.size(); ++i) {
        int j = i + 1;
        if (j >= p.size()) j -= p.size();
        sum += crs(p[i], p[j]);
    }
    return sum / 2.0L;
}