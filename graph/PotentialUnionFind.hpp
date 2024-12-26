#pragma once

// test: https://atcoder.jp/contests/abc087/submissions/61074288
/*
S, op の要件
- 結合律 (a*b)*c = a*(b*c)
- 交換律 a*b = b*a
- 単位元がある a*e = a
- 逆元がある inv(a)*a = e
*/
template <class S, S(*op)(S,S), S(*inv)(S), S(*e)()>
struct PotentialUnionFind {
	vector<int> par, rank;
	vector<S> diff_weight;

    // O(N)
	PotentialUnionFind(int n) : par(n), rank(n), diff_weight(n, e()) {
        iota(ALL(par),0);
	}

    // O(a)
	int root(int x) {
		if (par[x] == x) return x;

		int r = root(par[x]);
        diff_weight[x] = op(diff_weight[x], diff_weight[par[x]]);
        return par[x] = r;
	}

    // O(a)
	S weight(int x) {
		root(x);
		return diff_weight[x];
	}

    // O(a)
	bool same(int x, int y) {
		return root(x) == root(y);
	}

    // O(a)
	bool unite(int x, int y, S w) {
        w = op(w, weight(x));
        w = op(w, inv(weight(y)));
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y), w = inv(w);
		if (rank[x] == rank[y]) ++rank[x];
		par[y] = x;
		diff_weight[y] = w;
		return true;
	}

    // O(a)
	S diff(int x, int y) {
		return op(weight(y), inv(weight(x)));
	}
};