#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //@KhaledNinjo |v0.0.4
#define pb            push_back
#define sz(x)        ((int)(x.size()))
#define all(x)        x.begin(),x.end()
#define out(x)       return cout<<x,0
#define rep(i,n)     for(int i=0;i<n;i++)
#define clr(x)        memset(x,0,sizeof x)
short dx[] = { 1, 0, -1, 0 }, dy[] = { 0, -1, 0, 1 };
// echo 'goo.gl/opDifN'|wget -O- -i->main.cpp
const int inf = (1953125 << 9);
const int maxn = 1 + 1e6;

bool vis[maxn];
int n, m, idx = -1;
vector<int> nodes, final, G[maxn];
vector<pair<vector<int>, vector<int>>> res;

void run(int nextNode)
{
	if (vis[nextNode])
		return;
	res.back().first.pb(nextNode);
	res.back().second.pb(nodes[nextNode]);
	vis[nextNode] = true;
	rep(i,sz(G[nextNode]))
		run(G[nextNode][i]);
}
int main(void)
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	cin >> n >> m;
	nodes.resize(n);
	rep(i,n)
		cin >> nodes[i];
	rep(i,m)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].pb(b);
		G[b].pb(a);
	}

	clr(vis);
	rep(i,n)
	{
		if (!vis[i])
		{
			res.pb(pair<vector<int>, vector<int>>());
			run(i);
			sort(all(res.back().second), greater<int>());
			sort(all(res.back().first));
		}
	}
	final = nodes;
	rep(i,sz(res))
	{
		rep(j,sz(res[i].first))
		{
			final[res[i].first[j]] = res[i].second[j];
		}
	}
	rep(i,n)
		cout << final[i] << (i < n - 1 ? ' ' : '\n');
}
