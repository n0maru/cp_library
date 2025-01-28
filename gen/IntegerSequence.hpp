// untested
// need: Xorshift rnd (global)
vector<ll> gen_int_seq(int len, ll lowerBound, ll upperBound) {
    vector<ll> res(len);
    for (int i = 0; i < len; ++i) {
        res[i] = rnd(lowerBound, upperBound);
    }
    return res;
}