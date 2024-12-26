#pragma once
#include "../graph.hpp"

// O(N + M)
pair<vector<int>, int> bfs(const uwgraph& g, int start) {
    int n = g.size();
    vector<int> dis(n, 1e9), pre(n, -1);
    queue<int> q;
    dis[start] = 0;
    q.push(start);
    int ma = 0;
    int farthest = start;
    while (q.size()) {
        int pos = q.front();
        q.pop();
        for (int to : g[pos]) {
            if (dis[pos] + 1 < dis[to]) {
                dis[to] = dis[pos] + 1;
                pre[to] = pos;
                q.push(to);
                if (dis[to] > ma) {
                    ma = dis[to];
                    farthest = to;
                }
            }
        }
    }
    return {pre, farthest};
}

// 木の中心を求める(木の直径の中央の頂点)
// 1or2頂点
vector<int> center(const uwgraph& tree) {
    auto [pre1, v1] = bfs(tree, 0);
    auto [pre2, v2] = bfs(tree, v1);

    vector<int> path;
    int now = v2;
    while (now != -1) {
        path.push_back(now);
        now = pre2[now];
    }

    vector<int> centers;
    centers.push_back(path[path.size() / 2]);
    if (path.size() % 2 == 0) centers.push_back(path[path.size() / 2 - 1]);
    return centers;
}
// 木の名前を求める
int name(int pos, int pre, const uwgraph& tree, map<vector<int>,int>& cmp, int& id) {
    vector<int> seq;
    for (int c : tree[pos]) {
        if (c == pre) continue;
        seq.push_back(name(c, pos, tree, cmp, id));
    }
    if (seq.empty) {
        return 0;
    }
    sort(ALL(seq));
    if (cmp.count(seq)) {
        return cmp.at(seq);
    } else {
        cmp[seq] = ++id;
        return id;
    }
}
// 根付き木の同型性判定
// 定数倍重めのO(N logN)
bool isomorphism_rooted(const uwgraph& t1, const uwgraph& t2, int r1, int r2) {
    int id = 0;
    map<vector<int>, int> cmp;
    int name1 = name(r1, -1, t1, cmp, id);
    int name2 = name(r2, -1, t2, cmp, id);
    return (name1 == name2);
}
// 木の同型性判定
// 定数倍重めのO(N logN)
bool isomorphism(const uwgraph& t1, const uwgraph& t2) {
    auto cen1 = center(t1);
    auto cen2 = center(t2);
    if (cen1.size() != cen2.size()) {
        return false;
    }
    for (int c : cen1) {
        if (isomorphism_rooted(t1, t2, c, cen2[0])) return true;
    }
    return false;
}