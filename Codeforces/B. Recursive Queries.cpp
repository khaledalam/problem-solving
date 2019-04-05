#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const int maxn = 1 + 1e6;

int f(int x)
{
	if (x < 10)
		return x;
	ll ret = 1;
	while (x)
	{
		if (x % 10)
		{
			ret *= (x % 10);
		}
		x /= 10;
	}
	return f(ret);
}
int a[10][maxn];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxn; ++i)
	{
		a[f(i)][i] = 1;
	}

	for (int j = 0; j < 10; ++j)
	{
		for (int i = 0; i < maxn; ++i)
		{
			a[j][i] += a[j][i - 1];
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int x, y, k;
		cin >> x >> y >> k;
		cout << a[k][y] - a[k][x-1] << endl;
	}

}
