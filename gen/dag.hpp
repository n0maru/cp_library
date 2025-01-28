// untested
/*
need
- atcoder/dsu
- XorShift rnd (global)
- graph/graph.hpp
- gen/undirected_graph.hpp

generate undirected graph
O(m logm)

attentions
- generated graph is simple
*/
template<class T>
vector<edge2<T>> gen_dag(int n, int m, bool weak_connected, T lb = 0, T ub = 0) {
    return gen_undirected_graph(n, m, weak_connected, lb, ub);
}