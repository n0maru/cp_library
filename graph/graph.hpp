#pragma once

template <class T>
struct edge {
    int to;
    T cost;
    int id;
    edge(int to, T cost = 1, int id = -1) : to(to), cost(cost), id(id) {}
};
template <class T> using graph = vector<vector<edge<T>>>;
using gll = graph<ll>;
using gint = graph<int>;
using uwgraph = vector<vector<int>>;
template <class T>
ostream& operator <<(ostream& out, const edge<T>& e) {
    out << '[' << e.to << ' ' << e.cost << ' ' << e.id << ']';
    return out;
}

// 重み無しグラフに変換
// O(V+E)
template <class T>
uwgraph convert_uw(const graph<T>& g) {
    int n = g.size();
    uwgraph res(n);
    for (int i = 0; i < n; ++i) {
        for (auto&& e : g[i]) {
            res[i].push_back(e.to);
        }
    }
    return res;
}