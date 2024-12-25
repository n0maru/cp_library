#pragma once
class Comb
{
  int siz, mod;
  vector<long long> _fac, _inv, _finv;
public:
  // 引数は (mod)
  Comb(int m) : mod(m), siz(2)
  {
    _fac.resize(siz);
    _inv.resize(siz);
    _finv.resize(siz);
    _fac[0] = _fac[1] = _inv[1] = _finv[0] = _finv[1] = 1;
  }
  long long p(int n, int k)
  {
    if (n < k || k < 0) return 0;
    resize(n + 1);
    return _fac[n] * _finv[n - k] % mod;
  }
  long long c(int n, int k)
  {
    if (n < k || k < 0) return 0;
    resize(n + 1);
    return _fac[n] * _finv[k] % mod * _finv[n - k] % mod;
  }
  long long inv(int n)
  {
    assert(n >= 0);
    resize(n + 1);
    return _inv[n];
  }
  long long fac(int n)
  {
    assert(n >= 0);
    resize(n + 1);
    return _fac[n];
  }
  long long finv(int n)
  {
    assert(n >= 0);
    resize(n + 1);
    return _finv[n];
  }
private:
  void resize(int n)
  {
    if (n <= siz) return;
    for (int i = siz; i < n; ++i)
    {
      _fac.push_back((long long)i * _fac[i - 1] % mod);
      _inv.push_back(mod - _inv[mod % i] * (mod / i) % mod);
      _finv.push_back(_finv[i - 1] * _inv[i] % mod);
    }
    siz = n;
  }
};