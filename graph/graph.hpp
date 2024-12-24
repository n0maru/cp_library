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