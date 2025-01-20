template<class T>
vector<int> bfs(const graph<T>& g, int start) {
    int n = g.size();
    vector<int> dis(n, inf<int>);
    queue<int> q;
    dis[start] = 0;
    q.push(start);

    while (q.size()) {
        int pos = q.front();
        q.pop();

        for (auto&& e : g[pos]) {
            if (dis[e.to] > dis[pos] + 1) {
                dis[e.to] = dis[pos] + 1;
                q.push(e.to);
            }
        }
    }
    return dis;
}