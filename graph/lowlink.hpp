#pragma once
#include "graph.hpp"

//test: GRL-3-A, GRL-3-B
/*
コンストラクタを呼び出したら，art に関節点が列挙され，bri に橋が列挙される
*/
struct lowlink
{
	struct edge { int to, rev, stat; };
	int n, num;
	//art:関節点, bri:橋の集合
	vector<vector<edge>> g;
	vector<int> ord, low, art; 
	vector<pii> bri;
	// n:|V|, e:辺集合
	// O(|V|+|E|)
	lowlink(int n, vector<pii> &e)
    : n(n)
	{
		g.resize(n);
		ord.resize(n);
		low.assign(n, n + 1);
		for (auto& [a,b] : e)
		{
			edge e1{b, (int)g[b].size(), 0}, e2{a, (int)g[a].size(), 0};
			g[a].push_back(e1);
			g[b].push_back(e2);
		}

        num = 0;
		for (int i = 0; i < n; ++i)
		{
			if (ord[i] == 0)
			{
				dfs(i);
				ord[i] = -ord[i];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			// articulation & bridge
			bool isroot = ord[i] < 0, flag = false;
			if (isroot)
			{
				ord[i] = -ord[i];
				int cnt = 0;
				for (auto &v : g[i]) cnt += v.stat == 1;
				flag = cnt > 1;
			}
			for (auto &v : g[i])
			{
				if (v.stat == 1)
				{
					if (!isroot && ord[i] <= low[v.to]) flag = true;
					if (ord[i] < low[v.to]) bri.push_back({i, v.to});
				}
			}
			if (flag) art.push_back(i);
		}
	}
private:
	void dfs(int now)
	{
		ord[now] = ++num;
		int mi = ord[now];
		for (auto &v : g[now])
		{
			if (ord[v.to] == 0)
			{
				v.stat = 1;
				g[v.to][v.rev].stat = 2;
				dfs(v.to);
			}
			if (v.stat == 0) mi = min(mi, ord[v.to]);
			else if (v.stat == 1) mi = min(mi, low[v.to]);
		}
		low[now] = mi;
	}
};