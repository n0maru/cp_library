#pragma once
#include "../other/const.hpp"
#include "graph.hpp"

// test: https://atcoder.jp/contests/arc005/submissions/61071912
// O( k(V+E) )
template <class T>
vector<T> kbfs(const graph<T>& g, int start, int k) {
    int n = g.size();
    deque<queue<int>> qs(k);
    vector<ll> dis(n, inf<T>);
    vector<bool> vis(n);

    int item_num = 1;
    qs[0].emplace(start);
    dis[start] = 0;

    while (item_num > 0) {
        while (qs[0].empty) {
            qs.pop_front();
            qs.emplace_back();
        }
        int pos = qs[0].front();
        qs[0].pop();
        --item_num;
        if (vis[pos]) continue;
        vis[pos] = true;

        for (auto&& e : g[pos]) {
            if (dis[e.to] > dis[pos] + e.cost) {
                dis[e.to] = dis[pos] + e.cost;
                qs[e.cost].emplace(e.to);
                ++item_num;
            }
        }
    }
    return dis;
}