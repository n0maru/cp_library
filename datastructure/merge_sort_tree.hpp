#pragma once

template<typename T> class mergeSortTree
{
private:
    int num;
    vector<vector<T>> dat;
public:
    // O(NlogN)
    mergeSortTree(vector<T> &v)
    {
        int siz = static_cast<int>(v.size());
        for (num = 1; num < siz; num <<= 1);
        dat.resize(2 * num - 1);
        for (int i = 0; i < siz; ++i) dat[i + num - 1].push_back(v[i]);
        for (int i = num - 2; i >= 0; --i) merge(dat[i * 2 + 1].begin(), dat[i * 2 + 1].end(), dat[i * 2 + 2].begin(), dat[i * 2 + 2].end(), back_inserter(dat[i]));
    }
    // [left : right)のx以下の個数
    // O((logN)^2)
    long long getval(int left, int right, T x)
    {
        long long ans = 0;
        for (left += num - 1, right += num - 1; left < right; left >>= 1, right >>= 1)
        {
            if (!(left & 1)) ans += cal(left, x);
            if (--right & 1) ans += cal(right, x);
        }
        return ans;
    }
private:
    long long cal(int id, T x)
    {
        return upper_bound(dat[id].begin(), dat[id].end(), x) - dat[id].begin();
    }
};