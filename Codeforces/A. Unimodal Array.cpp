//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int idx = 1;
	bool st[3] = { 0 };

	while (idx < n && a[idx - 1] < a[idx])
	{
		idx++, st[0] = true;
	}

	while (idx < n && a[idx - 1] == a[idx])
	{
		idx++, st[1] = true;
	}
	while (idx < n && a[idx - 1] > a[idx])
	{
		idx++, st[2] = true;
	}

	return puts( (n == 1 || ((idx == n) && (st[0] || st[2] || st[1]))) ? "YES" : "NO");

}
