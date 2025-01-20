/*
コンストラクタでSCC分解を行う
agg                 SCCをして縮約したグラフ
強連結成分はトポロジカルソートされている．
つまり異なる強連結成分の頂点 u,v について，u から v に到達できる時，u の属するリストは v の属するリストよりも前にある．
*/
template <class T>
struct SCC {
    const int n;
    graph<T> g, rev, agg;
    vector<bool> vis;
    vector<int> compo, out;

    SCC(const graph<T> &g)
    : n(g.size()), g(g), rev(n), agg(), compo(n, -1), out() {
        // revの構築
        for (int i = 0; i < n; ++i) {
            for (auto [to, cost] : g[i]) {
                rev[to].emplace_back(i, cost);
            }
        }
        build();
    }
    // 頂点iの所属する強連結成分の番号
    int operator[](int idx) {
        return compo[idx];
    }
    // 強連結成分の数
    int size() {
        return agg.size();
    }

    void dfs(int pos) {
        if (vis[pos]) return;
        vis[pos] = true;

        for (auto [to, cost] : g[pos]) {
            dfs(to);
        }
        out.push_back(pos);
    }

    void rdfs(int pos, int group) {
        if (vis[pos]) return;
        vis[pos] = true;
        if (compo[pos] != -1) return;
        compo[pos] = group;

        for (auto [to, cost] : rev[pos]) {
            rdfs(to, group);
        }
    }
    void build() {
        vis.assign(n, false);
        for (int i = 0; i < n; ++i) {
            dfs(i);
        }
        reverse(out.begin(), out.end());

        int group = 0;
        vis.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!vis[out[i]]) {
                rdfs(out[i], group);
                ++group;
            }
        }

        // 集約したグラフの構築
        agg.resize(group);
        for (int i = 0; i < n; ++i) {
            for (auto [to, cost] : g[i]) {
                int u = compo[i];
                int v = compo[to];
                if (u != v) agg[u].emplace_back(v, cost);
            }
        }
    }
};