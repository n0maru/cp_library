#pragma once
ll modpow(ll x, ll n, ll mod) {
    x %= mod;
    ll res = 1;
    while (n > 0) {
        if (n&1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}