#pragma once
#include "../graph.hpp"

// test: https://atcoder.jp/contests/ABC222/submissions/61075960
/*
重み付き無向木
注意：末端の値は addRoot(e()) になる
dp[v][i] := v から出る i 番目の有向辺に対応する部分木の値

S: モノイド
e: S の単位元を返す
W: 辺の重み
id: W の単位元を返す
op: 子の部分木をmergeする
addRoot(S,W,parent,child,eid): 子の頂点までの値sに，親と子の間の辺の重みwを反映させる(parent=-1,eid=-1のときがある)
*/
template<class S, S (*op)(S, S), S (*e)(), class W, W (*id)(), S (*addRoot)(S, W, int, int, int)>
class Rerooting {
public:
    // O(V+E)
    Rerooting(const graph<W>& g)
    : g(g)
    , dp(g.size())
    , a(g.size(), e())
    {
        dfs(0);
        dfs2(0, e());
    }
    // O(1)
    S ans(int idx) {
        return a[idx];
    }
private:
    S dfs(int v, int p = -1) {
        S cum = e();
        int deg = g[v].size();
        dp[v] = vector<S>(deg, e());
        int eid = -1;
        W pw = e();
        for (int i = 0; i < deg; ++i) {
            int u = g[v][i].to;
            if (u == p) {
                eid = g[v][i].id;
                pw = g[v][i].cost;
                continue;
            }
            dp[v][i] = dfs(u, v);
            cum = op(cum, dp[v][i]);
        }
        return addRoot(cum, pw,p,v,eid);
    }
    void dfs2(int v, const S& s, int p = -1) {
        int deg = g[v].size();
        for (int i = 0; i < deg; ++i) {
            if (g[v][i].to == p) dp[v][i] = s;
        }
        vector<S> dpl(deg + 1, e()), dpr(deg + 1, e());
        for (int i = 0; i < deg; ++i) {
            dpl[i + 1] = op(dpl[i], dp[v][i]);
        }
        for (int i = deg-1; i >= 0; --i) {
            dpr[i] = op(dp[v][i], dpr[i + 1]);
        }
        a[v] = addRoot(dpl[deg], id(),-1,v,-1);
        for (int i = 0; i < deg; ++i) {
            auto [u,w,eid] = g[v][i];
            if (u == p) continue;
            dfs2(u, addRoot(op(dpl[i], dpr[i + 1]),w,u,v,eid), v);
        }
    }

    const graph<W>& g;
    vector<vector<S>> dp;
    vector<S> a;
};