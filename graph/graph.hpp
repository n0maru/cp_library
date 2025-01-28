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

// convert to unweighted graph
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

template <class T>
struct edge2 {
    int from;
    int to;
    T cost;
    int id;
    edge2(int from, int to, T cost = 1, int id = -1) : from(from), to(to), cost(cost), id(id) {}
};
template <class T>
ostream& operator <<(ostream& out, const edge2<T>& e) {
    out << '[' << e.from << ' ' << e.to << ' ' << e.cost << ' ' << e.id << ']';
    return out;
}