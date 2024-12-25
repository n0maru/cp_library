#pragma once

// returns[i] ... s[0..n]とs[i..n]の最長共通接頭辞(lcp)の長さ
// O(|s|)
std::vector<int> Z_algorithm(std::string &s)
{
	int c = 0, n = s.size();
	std::vector<int> ret(n);
	for (int i = 1; i < n; ++i)
	{
		int l = i - c;
		if (i + ret[l] < c + ret[c]) ret[i] = ret[l];
		else
		{
			int j = std::max(0, c + ret[c] - i);
			while (i + j < n && s[i + j] == s[j]) ++j;
			ret[i] = j;
			c = i;
		}
	}
	ret[0] = n;
	return ret;
}