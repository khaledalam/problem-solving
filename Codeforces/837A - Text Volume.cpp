//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, res = 0;
	cin >> n;
	string s;
	while (cin >> s)
	{
		int cnt = 0;
		for (int i = 0; i < (int) s.size(); ++i)
		{
			if (isupper(s[i])) cnt++;
			res = max(res, cnt);
		}
	}
	cout << res;
}

