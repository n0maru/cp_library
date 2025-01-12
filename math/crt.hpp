//(val, lcm(m1, m2)): val=b1(mod m1), val=b2(mod m2)
// 解なしの場合は (0, -1) をリターン
std::pair<long long, long long> crt(long long b1, long long m1, long long b2, long long m2)
{
    long long x = 1, y = 0, x1 = 0, y1 = 1, g = m1, b = m2;
    while (b != 0)
    {
        long long n = g / b;
        g %= b; std::swap(g, b);
        x -= x1 * n; std::swap(x, x1);
        y -= y1 * n; std::swap(y, y1);
    }
    if ((b2 - b1) % g != 0) return {0, -1};
    long long lc = m1 / g * m2;
    return {((b1 + m1 * ((b2 - b1) / g * x % (m2 / g))) % lc + lc) % lc, lc};
}