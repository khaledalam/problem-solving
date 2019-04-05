//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, mi, mx;
stringstream ss;
//http://codeforces.com/contest/489/problem/C
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if(!m && n > 1)return puts("-1 -1"), 0;
	int hold = m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 9; j >= 0; --j)
		{
			if (hold >= j)
			{
				ss << j;
				hold -= j;
				break;
			}
		}
	}
	ss >> mx;
	ss.clear();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if( (!i && !j && n > 1) || j > m || m-j > 9 * (n-i-1) )continue;
			if (m >= j)
			{
				ss << j;
				m -= j;
				break;
			}
		}
	}
	ss >> mi;
	if (hold || m) return puts("-1 -1"), 0;
	cout << mi << ' ' << mx << endl;
}
