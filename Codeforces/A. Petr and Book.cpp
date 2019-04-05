//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, cnt = 0, a[7];
	cin >> n;
	for (int i = 0; i < 7; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; ; i = (i + 1) % 7)
	{
		if (n < 1) return cout<<(i==0?7:i), 0;
		n -= a[i]; if (a[i])cnt++;
	}
}
