#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define ALL(v) v.begin(),v.end()
#define sq(x) ((x) * (x))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a=b; return true; } else { return false; } }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a=b; return true; } else { return false; } }
template <class F, class S> ostream& operator<<(ostream &os, const pair<F,S>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
void YesNo(bool ans) { cout << (ans ? "Yes" : "No") << '\n'; }
void YESNO(bool ans) { cout << (ans ? "YES" : "NO") << '\n'; }
#define UNIQUE(v) sort(ALL(v)); v.erase(unique(ALL(v)), v.end());

#ifdef LOCAL
template <class T> void dbgv(const vector<T>& v) { cerr << "\033[31m"; for (auto&& i : v) { cerr << i << ' '; } cerr << "\033[m" << endl; }
template <class T> void dbgvv(const vector<vector<T>>& v) { for (auto&& i : v) { for (auto&& j : i) { cerr << j << ' '; } cerr << endl; } }
template <class T, size_t U> void dbga(const array<T,U>& v) { for (auto&& i : v) { cerr << i << ' '; } cerr << endl; }
void dbg() { cerr << endl; }
template <class Head, class... Tail> void dbg(const Head& head, const Tail& ...tail) { cerr << head << ' '; dbg(tail...); }
void grid(const vector<string>& g) { for (auto&& line : g) { cerr << line << endl; } }
#else
template <class T> void dbgv(const vector<T>&) {}
template <class T> void dbgvv(const vector<vector<T>>&) {}
template <class T, size_t U> void dbga(const array<T,U>&) {}
void dbg() {}
template <class Head, class... Tail> void dbg(const Head&, const Tail& ...) {}
void grid(const vector<string>&) {}
#endif

template <class T> static constexpr T inf = numeric_limits<T>::max() / 2;
// 未テスト
// 上から反時計回り
int dx4[] = { 0, -1, 0, 1 };
int dy4[] = { -1, 0, 1, 0 };
int dx8[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy8[] = { -1, -1, 0, 1, 1, 1, 0, -1 };



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    
}