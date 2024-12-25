#pragma once
#include "../graph.hpp"

// test: https://judge.yosupo.jp/submission/258368
/*
最小共通祖先をダブリングにより求める
*/
class LCA {
public:
    int log;
    uwgraph g;
    vector<vector<int>> par;
    vector<int> dist;

    // O(N+M)
    template <class T>
    LCA(const graph<T>& wg, int root = 0) : g(convert_uw(wg)) {
        init(root);
    }
    // 頂点uと頂点vのLCAを求める
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);
        for (int k = 0; k < log; ++k) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = par[k][u];
            }
        }
        if (u == v) return u;
        for (int k = log-1; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }
    // 頂点uと頂点vのパス上に頂点aがあるならtrue
    // O(1)
    bool isOn(int u, int v, int a) {
        return (dis(u,v) == dis(u,a) + dis(v,a));
    }
    // 頂点uと頂点vの間の距離
    // O(1)
    int dis(int u, int v) {
        return dist[u] + dist[v] - 2 * dist[query(u,v)];
    }
private:
    void init(int root = 0) {
        int n = g.size();
        log = 1;
        while ((1 << log) < n) log++;
        par.assign(log, vector<int>(n, -1));
        dist.assign(n, -1);
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < log; ++k) {
            for (int i = 0; i < g.size(); ++i) {
                if (par[k][i] < 0) {
                    par[k + 1][i] = -1;
                } else {
                    par[k + 1][i] = par[k][ par[k][i] ];
                }
            }
        }
    }
    void dfs(int v, int pre, int d) {
        par[0][v] = pre;
        dist[v] = d;
        for (auto to : g[v]) {
            if (to == pre) continue;
            dfs(to, v, d + 1);
        }
    }
};