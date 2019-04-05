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
const int maxn = 1 + 1e5;

struct edge
{
	ll target, val;
	edge(ll _target, ll _val) : target(_target), val(_val){}
};
vector<edge> g[maxn];
ll n, res = 0;

ll mxPath(int from, int to)
{
	ll len = 0;
	for (int i = 0; i < sz(g[to]); ++i)
	{
		if (g[to][i].target != from)
		{
			len = max(len, g[to][i].val + mxPath(to, g[to][i].target));
		}
	}
	return len;
}
int main(void)
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	cin >> n;
	rep(i,n-1)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		res += c;
		g[a].pb(edge(b, c));
		g[b].pb(edge(a, c));
	}
//	out(mxPath(-1, 0));
	cout << (res << 1) - mxPath(-1, 0);
}
