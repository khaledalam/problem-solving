//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	if (n < m)
	{
		cout << n + 1 << endl;
		int c = 0;
		for (int i = m; i >= m - n; i--)
		{
			cout << c++ << ' ' << i << endl;
		}
	}
	else
	{
		cout << m + 1 << endl;
		int c = 0;
		for (int i = n; i >= n - m; i--)
		{
			cout << i << ' ' << c++ << endl;
		}
	}
}
