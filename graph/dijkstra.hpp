// #include "graph.hpp"

// aoj GRL-1-A
// O((V+E) logV)
template <class T>
vector<T> dijkstra(const graph<T>& g, int start) {
    int n = g.size();
    vector<ll> dis(n, inf<T>);
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