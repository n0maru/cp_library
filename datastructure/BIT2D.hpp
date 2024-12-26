#pragma once
struct BIT2D {
    // 全てのマスを0で初期化
    // O(hw)
    BIT2D(int h, int w) : H(h), W(w), dat(h+1, vector<ll>(w+1, 0)) {}

    // マス(x,y)にvalを加算
    // O(logH * logW)
    void add(int x, int y, ll val) {
        ++x; ++y;
        for (int a = y; a <= H; a += a & -a) {
            for (int b = x; b <= W; b += b & -b) {
                dat[a][b] += val;
            }
        }
    }

    // [(0,0), (x,y))の総和
    // O(logH * logW)
    ll sum(int x, int y) {
        ll s = 0;
        for (int a = y; a > 0; a -= a & -a) {
            for (int b = x; b > 0; b -= b & -b) {
                s += dat[a][b];
            }
        }
        return s;
    }

    // [(x1,y1), (x2,y2))の総和
    // O(logH * logW)
    ll sum(int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return 0;
        return sum(x2,y2) - sum(x2,y1) - sum(x1,y2) + sum(x1,y1);
    }

    int H,W;
    vector<vector<ll>> dat;
};