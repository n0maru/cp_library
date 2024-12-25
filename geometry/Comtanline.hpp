#pragma once
#include "template.hpp"

// 2つの円の共通の接線
// 接線の本数は0～4本
// O(1)
vector<Line> comtanline(Circle c1, Circle c2) {
	vector<Line> res;
	if(c1.radius < c2.radius) {
        swap(c1, c2);
    }
    auto [cen1, r1] = c1;
    auto [cen2, r2] = c2;
	const ld g = (cen1 - cen2).abs();
	if(sgn(g) == 0) return res;
	const Vec e = (cen2 - cen1) / g;
	const Vec n = Vec{e.y, -e.x};
	for(int s : {-1, 1}) {
		ld h = (r1 + s * r2) / g;
		if(sgn(1 - h * h) == 0) {
			res.emplace_back(cen1 + e * r1, cen1 + (e + n) * r1);
		} else if(1 - h * h > 0) {
			Point u = e * h, v = n * sqrtl(1 - h * h);
			res.emplace_back(cen1 + (u + v) * r1, cen2 - (u + v) * r2 * ld(s));
			res.emplace_back(cen1 + (u - v) * r1, cen2 - (u - v) * r2 * ld(s));
		}
	}
	return res;
}