#pragma once
#include "../other/const.hpp"
#include "graph.hpp"

// test: https://atcoder.jp/contests/arc005/submissions/61285177
// O( k(V+E) )
vector<int> kbfs(const gint& g, int start, int k) {
    int n = g.size();
    deque<queue<int>> qs(k);
    vector<int> dis(n, inf<int>);

    int item_num = 1;
    int nowd = 0;
    qs[0].emplace(start);
    dis[start] = 0;

    while (item_num > 0) {
        while (qs[0].empty()) {
            qs.pop_front();
            qs.emplace_back();
            ++nowd;
        }
        int pos = qs[0].front();
        qs[0].pop();
        --item_num;
        if (nowd > dis[pos]) continue;

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