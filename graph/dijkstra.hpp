#pragma once
#include "graph.hpp"

// 未テスト
// O((V+E) logV)
vector<ll> dijkstra(const graph& g, int start) {
    int n = g.size();
    ll inf = 1e18;
    vector<ll> dis(n, inf);
    priority_queue<pll> pq;
    dis[start] = 0;
    pq.emplace(0, start);
    
    while (pq.size()) {
        auto [cost, pos] = pq.top();
        pq.pop();
        cost = -cost;
        if (cost > dis[pos]) continue;
        for (auto&& e : g[pos]) {
            if (dis[e.to] > dis[pos] + e.cost) {
                dis[e.to] = dis[pos] + e.cost;
                pq.emplace(-dis[e.to], e.to);
            }
        }
    }
    return dis;
}