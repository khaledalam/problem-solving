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

int n, m, k;
bool vis[maxn];

int main(void)
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;

//	cout<<(m-n-1)<<" "<<((n-2) * (n - 3) / 2)<<endl;return 0;
	if (m < n - 1 || (m-n-1) >= ((n-2) * (n - 3) / 2)-1)
		out(-1);

	cout << (k == 1 ? 2 : 1) << ' ' << k << endl;
	m--;
	clr(vis);
	vis[0] = vis[(k == 1 ? 2 : 1)] = vis[k] = true;
	rep(i,n+1)
	{
		if (vis[i])
			continue;
		m--;
		cout << k << ' ' << i << endl;
	}

	int i = 2;
	for (; i <= n && m; ++i)
	{
		if (vis[i])
			continue;
		vis[i] = true;
		for (int j = i; j <= n && m; ++j)
		{
			if (vis[j])
				continue;
			m--;
			cout << i << ' ' << j << endl;
			if (!m)
				break;
		}
		if (!m)
			break;

	}
}
