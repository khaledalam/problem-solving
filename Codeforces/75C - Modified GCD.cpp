#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e5 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
	// freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	int a, b;
	cin >> a >> b;
	int g = __gcd(a, b);
	vector<int> divs;
	for (int i = 1; i * i <= g; i++)
	{
		if (g % i == 0)
		{
			divs.push_back(i);
			if (i * i != g)
				divs.push_back(g / i);
		}
	}

	sort(divs.begin(), divs.end());

	int q;
	cin >> q;
	while (q--)
	{
		int aa, bb;
		cin >> aa >> bb;
		int l = 0, r = (int)divs.size() - 1;
		int mid, res = -1, opt = 50;
		while (--opt)
		{
			mid = (l + r) >> 1;
			if (divs[mid] >= aa && divs[mid] <= bb)
			{
				l = mid + 1;
				res = max(res, divs[mid]);
			}
			else if (divs[mid] < aa)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << res << endl;
	}
}
