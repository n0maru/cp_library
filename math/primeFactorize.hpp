vector<pair<ll,int>> primeFactorize(ll x) {
    vector<pair<ll,int>> res;
    for (ll i = 2; i * i <= x; ++i) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            ++cnt;
        }
        if (cnt > 0) {
            res.emplace_back(i, cnt);
        }
    }
    if (x > 1) {
        res.emplace_back(x, 1);
    }
    return res;
}