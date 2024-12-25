#pragma once

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a=b; return true; } else { return false; } }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a=b; return true; } else { return false; } }
template <class F, class S> ostream& operator<<(ostream &os, const pair<F,S>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
void YesNo(bool ans) { cout << (ans ? "Yes" : "No") << '\n'; }
void YESNO(bool ans) { cout << (ans ? "YES" : "NO") << '\n'; }

#ifndef ONLINE_JUDGE

template <class T> void dbgv(const vector<T>& v) { for (auto&& i : v) { cerr << i << ' '; } cerr << endl; }
template <class T> void dbgvv(const vector<vector<T>>& v) { for (auto&& i : v) { for (auto&& j : i) { cerr << j << ' '; } cerr << endl; } }
template <class T, size_t U> void dbga(const array<T,U>& v) { for (auto&& i : v) { cerr << i << ' '; } cerr << endl; }
void dbg() { cerr << endl; }
template <class Head, class... Tail> void dbg(const Head& head, const Tail& ...tail) { cerr << head << ' '; dbg(tail...); }

#else

template <class T> void dbgv(const vector<T>&) {}
template <class T> void dbgvv(const vector<vector<T>>&) {}
template <class T, size_t U> void dbga(const array<T,U>&) {}
void dbg() {}
template <class Head, class... Tail> void dbg(const Head& head, const Tail& ...tail) {}

#endif