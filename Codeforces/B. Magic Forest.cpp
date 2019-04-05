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

ll n, cnt = 0;
bool ok(int x, int y, int z)
{
	if (x + y <= z)
		return false;
	if (x + z <= y)
		return false;
	if (z + y <= x)
		return false;
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	cin >> n;
	int i = 1, j = 1, k = 1;

	for (i = 1; i <= n; ++i)
	{
		for (j = i; j <= n; ++j)
		{
			k = (i ^ j);
			if (k < j || k > n)
				continue;
			if (!(i ^ j ^ k) && ok(i, j, k))
			{
//				cout << i << " " << j << " " << k << endl;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
