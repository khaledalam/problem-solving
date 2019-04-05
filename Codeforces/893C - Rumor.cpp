//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stringstream ss;
typedef pair<int, int> pii;
//#########################
#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define out(x)       return cout<<x,0
#define all(x)       x.begin(),x.end()
#define sz(x)        ((int)(x.size()))
#define clr(x)       memset(x,0,sizeof x)
#define rep(i,n)     for(int i=0;i<n;i++)
#define debug(x)     cerr<<"[l#: "<<__LINE__<<"] "<<#x<<" = "<<x<<endl
// v0.0.2 | Github.com/khaledalam/templates/tree/master/cpp
//##########################################################################

#define maxn 100100

int a[maxn], mi = 1e9;
bool vis[maxn];
vi g[maxn];

void runMn(int idx)
{
	mi = min(mi, a[idx]);
	for (int i = 0; i < sz(g[idx]); ++i)
	{
		if (!vis[g[idx][i]])
		{
			vis[g[idx][i]] = true;
			runMn(g[idx][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	rep(i,n)
		cin >> a[i];
	rep(i,m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	clr(vis);
	ll res = 0;
	rep(i,n)
	{
		if (!vis[i])
		{
			mi = a[i];
			vis[i] = true;
			runMn(i);
			res += mi;
		} else if (!vis[i] && !sz(g[i]))
			res += a[i];

	}
	cout << res << endl;
}

