//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	long long n, x, y, cur;
	cin >> n >> x >> y;

	if (n - 1 >= y) return puts("-1"), 0;

	cur += (y - (n - 1)) * (y - (n - 1)) + (n - 1);
	if (cur < x) return puts("-1"), 0;

	for (int i = 0; i < n - 1; i++)
		cout << 1 << endl;
	cout << (y - (n - 1)) << endl;
}
