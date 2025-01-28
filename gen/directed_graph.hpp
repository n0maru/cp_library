// untested
/*
need
- atcoder/dsu
- XorShift rnd (global)
- graph/graph.hpp

generate directed graph
O(m logm)

attentions
- generated graph is simple
*/
template<class T>
vector<edge2<T>> gen_directed_graph(int n, int m, bool weak_connected, T lb = 0, T ub = 0) {
    assert(m >= n - 1);
    assert(m <= n * (n - 1));
    bool weighted = ( ub - lb > 0 );

    vector<edge2<T>> res;
    set<pii> st;

    // make connected
    if (weak_connected) {
        dsu uf(n);
        for (int i = 1; i < n; ++i) {
            bool fn = false;
            do {
                int a = rnd() % n;
                if (uf.same(i, a)) continue;

                T cost = (weighted ? rnd(lb, ub) : 1);
                st.emplace(i, a);
                res.emplace_back(i, a, cost);
                uf.merge(i, a);
                fn = true;
            } while (!fn);
        }
    }
    
    // add extra edges
    while (st.size() < m) {
        int u = rnd() % n;
        int v = rnd() % n;
        if (u == v) continue;
        if (st.count({u, v})) { continue; }
        T cost = (weighted ? rnd(lb, ub) : 1);
        res.emplace_back(u, v, cost, -1);
        st.emplace(u, v);
    }

    // shuffle
    for (int i = 0; i < m; ++i) {
        swap(res[i], res[ rnd(0, i+1) ]);
    }

    return res;
}