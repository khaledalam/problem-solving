#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e5 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

int n, s, k;
vector<int> a;

long long calc(long long fact)
{
	long long ret = 0L;
	priority_queue<long long, vector<long long>, greater<long long>>sot;
	for (int i = 0; i < n; i++)
	{
		sot.push(a[i] + (i + 1) * fact);
	}
	while (fact--)
	{
		ret += sot.top();
		sot.pop();
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
	//freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	cin >> n >> s;
	k = n;
	a.resize(n);
	for (auto &it : a)
		cin >> it;

	long long l = 0, r = n + 1, mid = 0;
	while (l < r - 1)
	{
		mid = (l + r) >> 1;

		if (s >= calc(mid))
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}

	cout << l << " " << calc(l) << endl;
}
