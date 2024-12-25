#pragma once

// test: https://atcoder.jp/contests/abc383/submissions/61073604
/*
S の要件
- 結合律 (a*b)*c = a*(b*c)
- 交換律 a*b = b*a
*/
template <class S, S (*op) (S,S)>
struct UnionFind {
    vector<int> par, rank;
    vector<S> d;

    // O(N)
    UnionFind(const vector<S>& init) : par(init.size()), rank(init.size()), d(init) {
        iota(ALL(par), 0);
    }
    // O(a)
    int root(int x) {
        if (x == par[x]) return x;
        return par[x] = root(par[x]);
    }
    // O(a)
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (rank[x] > rank[y]) swap(x,y);
        if (rank[x] == rank[y]) ++rank[y];
        par[x] = y;
        d[y] = op(d[x], d[y]);

        return true;
    }
    // O(a)
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    // O(a)
    S& get(int index) {
        return d[ root(index) ];
    }
};