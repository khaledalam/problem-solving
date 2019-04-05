//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long a, b, x[100010], mi = 1e9, res = 0;
	cin >> a >> b;
	for (int i = 0; i < a; ++i)
	{
		cin >> x[i];
		mi = min(mi, x[i]);
	}
	for (int i = 0; i < a; ++i)
	{
		if ((x[i] - mi) % b != 0)return puts("-1"), 0;
		res += (x[i] - mi) / b;
	}
	cout << res << endl;
}
