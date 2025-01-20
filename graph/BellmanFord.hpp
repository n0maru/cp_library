// 定数倍悪い
// O(N(N+M))
// 負の閉路が存在する場合 true を返す
template<class T>
pair<vector<T>, bool> bellmanFord(const graph<T>& g, int start) {
    int n = g.size();
    vector<T> dis(n, inf<T>);
    dis[start] = T(0);

    for (int i = 0; i < n; ++i) {
        bool updated = false;

        for (int from = 0; from < n; ++from) {
            if (dis[from] == inf<T>) continue;

            for (auto&& e : g[from]) {

                if (dis[e.to] > dis[from] + e.cost) {
                    dis[e.to] = dis[from] + e.cost;
                    updated = true;
                }
            }
        }

        if (!updated) {
            return {dis, false};
        }
    }
    return {dis, true};
}

// 負閉路の影響を受ける頂点に -INF を伝播
template<class T>
void propagateNegativeLoop(const graph<T>& g, vector<T>& dis) {
    int n = g.size();
    for (int i = 0; i < n; ++i) {
        for (int from = 0; from < n; ++from) {
            if (dis[from] == inf<T>) continue;

            for (auto&& e : g[from]) {
                if (dis[e.to] > dis[from] + e.cost) {
                    dis[e.to] = -inf<T>;
                }
            }
        }
    }
}