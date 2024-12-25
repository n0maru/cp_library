#pragma once
#include "template.hpp"

// 点pが多角形gに内包されているか
// O(N)
#define IN (2)
#define ON (1)
#define OUT (0)
int isContain(Point p, Polygon poly) {
    int n = poly.size();
    bool x = false;
    for (int i = 0; i < n; ++i) {
        int j = i+1;
        if (j >= n) j -= n;
        Vec a = poly[i] - p, b = poly[j] - p;
        if (sgn(crs(a,b)) == 0 && sgn(dot(a,b)) <= 0) return ON;
        if (a.y > b.y) swap(a,b);
        if (sgn(a.y) <= 0 && sgn(b.y) > 0 && sgn(crs(a,b)) > 0) x = !x;
    }
    return (x ? IN : OUT);
}