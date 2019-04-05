//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	s.resize(n + 2);
	int op = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if (s[i] == '.' && s[i - 1] == '.')
		{
			op++;
		}
	}

	int x;
	char c, p = '.';
	for (int i = 0; i < m; i++)
	{
		cin >> x >> c;
		if (c == p)
		{
			if (s[x] != p)
			{
				if (s[x - 1] == p && s[x + 1] == p) op += 2;
				else if (s[x - 1] == p || s[x + 1] == p) op += 1;
				s[x] = c;
			}
		}
		else
		{
			if (s[x] == p)
			{
				if (s[x - 1] == p && s[x + 1] == p) op -= 2;
				else if (s[x - 1] == p || s[x + 1] == p) op -= 1;
				s[x] = c;
			}
		}
		cout << op << '\n';
	}
}
