#include <bits/stdc++.h>
using namespace std;

struct Prime {
    int size;
    vector<bool> isPrime;
    vector<int> primes;

    Prime(int n) : size(n), isPrime(size + 1, true)
    {
        build();
    }

    vector<pair<ll,int>> primeFactorize(ll x) {
        vector<pair<ll,int>> res;
        for (int p : primes) {
            if (p > x / p) break;
            int cnt = 0;
            while (x % p == 0) {
                ++cnt;
                x /= p;
            }
            if (cnt >= 1) {
                res.emplace_back(p, cnt);
            }
        }
        if (x > 1) res.emplace_back(x, 1);
        return res;
    }

    void build() {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= size; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (ll j = i * i; j <= size; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
    }
};