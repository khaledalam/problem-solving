#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 100;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	int n, sum = 0, sum2 = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sum = accumulate(a, a + n, 0) + 1;

	for (int i = 0; i < n; ++i)
	{
		sum2 += a[i];
		if ((sum >> 1) <= sum2)
			return cout << i + 1, 0;
	}
	cout << n;
}
