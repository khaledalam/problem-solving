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
const int maxn = 3 * 1e3;

ll n, k, cnt = 0;
map<ll, bool> vis;
int main(void)
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	cin >> n >> k;

	for (int i = 1; i <= k; ++i)
	{
		if (vis[n % i])
			out("No");
		vis[n % i] = true;
	}
	out("Yes");
}
