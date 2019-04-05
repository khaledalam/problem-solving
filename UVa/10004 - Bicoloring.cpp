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
const int maxn = 1 + 2 * 1e2;

vector<int> g[maxn];
bool vis[maxn];
vector<int> mark[2];
bool flag = false;
void run(int node, bool which)
{
	if (flag)
		return;
	if (find(all(mark[!which]), node) != mark[!which].end())
	{
		flag = true;
		puts("NOT BICOLORABLE.");
		return;
	}
	if (vis[node])
		return;
	vis[node] = true;
	mark[which].pb(node);

	rep(i, sz(g[node]))
		run(g[node][i], !which);
}

int main(void)
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	int n;
	while (cin >> n && n)
	{
		rep(i,maxn)
			g[i].clear();
		int edges;
		cin >> edges;
		while (edges--)
		{
			int a, b;
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		clr(vis);
		mark[0].clear(),mark[1].clear();
		flag = false;
		run(0, false);
		if (!flag)
			puts("BICOLORABLE.");
	}

}
