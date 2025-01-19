// 未テスト
// O(NlogN)
template <class T>
void compress(vector<T>& v) {
    auto cp = v;
    sort(ALL(cp));
    cp.erase(unique(ALL(cp)), cp.end());

    for (T& i : v) i = lower_bound(ALL(cp), i) - cp.begin();
}