struct XorShift {
    ll x;

    XorShift(ull seed = 722) : x(seed) {}

    ull operator()() {
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return x;
    }

    ull operator()(ull r) {
        return operator()() % r;
    }

    ull operator()(ull l, ull r) {
        return operator()(r - l) + l;
    }
} rnd;
