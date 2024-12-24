#pragma once

struct edge {
    int to;
    ll cost;
    int id;
};
using graph = vector<vector<edge>>;
ostream& operator <<(ostream& out, const edge& e) {
    out << '[' << e.to << ' ' << e.cost << ' ' << e.id << ']';
    return out;
}

// 未テスト
// 重み無しグラフに変換
// O(V+E)
vector<vector<int>> convert_uw(const graph& g) {
    int n = g.size();
    vector<vector<int>> res(n);
    for (int i = 0; i < n; ++i) {
        for (auto&& e : g[i]) {
            res[i].push_back(e.to);
        }
    }
    return res;
}