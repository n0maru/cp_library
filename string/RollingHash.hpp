#pragma once

struct RollingHash {
private:
    using ull = unsigned long long;
    static const ull mod = (1ULL << 61) - 1;
    static ull base;
    vector<ull> hashed, power;

    inline ull mul(ull a, ull b) const {
        ull au = a >> 31;
        ull ad = a & ((1ULL << 31) - 1);
        ull bu = b >> 31;
        ull bd = b & ((1ULL << 31) - 1);
        ull mid = ad * bu + au * bd;
        ull midu = mid >> 30;
        ull midd = mid & ((1ULL << 30) - 1);
        ull ans = au * bu * 2 + midu + (midd << 31) + ad * bd;

        ans = (ans >> 61) + (ans & mod);
        if (ans >= mod) ans -= mod;
        return ans;
    }
public:
    int size() const {
        return hashed.size() - 1;
    }
    // 文字列sから構築する
    // O(|s|)
    RollingHash(const string& s) {
        ll n = s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for (ll i = 0; i < n; ++i) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }
    // 区間[l,r)のハッシュ値の取得
    // O(1)
    ull get(ll l, ll r) const {
        assert(0 <= l && l <= size());
        assert(0 <= r && r <= size());
        ull ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod) ret -= mod;
        return ret;
    }
    // ハッシュh1に長さh2lenの文字列をもとにしたハッシュh2をつなげた結果を得る
    // O(1)
    ull connect(ull h1, ull h2, ll h2len) const {
        ull ret = mul(h1, power[h2len]) + h2;
        if (ret >= mod) ret -= mod;
        return ret;
    }
    // 文字列sを後ろにつなげる
    // O(|s|) 
    void connect(const string& s) {
        ll n = size(), m = s.size();
        hashed.resize(n + m + 1);
        power.resize(n + m + 1);
        for (ll i = n; i < n + m + 1; ++i) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i - n];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }
    // ロリハの[l1,r2)とロリハbの[l2, r2)は先頭から何文字一致するか
    // O(log(min(r1-l1,r2-l2)))
    ll lcp(const RollingHash& b, ll l1, ll r1, ll l2, ll r2) const {
        assert(0 <= l1 && l1 <= size());
        assert(0 <= r1 && r1 <= size());
        assert(0 <= l2 && l2 <= b.size());
        assert(0 <= r2 && r2 <= b.size());
        ll len = min(r1 - l1, r2 - l2);
        ll low = -1, high = len + 1;
        while (high - low > 1) {
            ll mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};
mt19937_64 mt{(unsigned int)time(NULL)};
RollingHash::ull RollingHash::base = mt() % RollingHash::mod;