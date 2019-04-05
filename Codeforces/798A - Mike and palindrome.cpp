
 //@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s, a, b;
	int cnt = 0;
	cin >> s;
	if (s.size() == 1)return cout << "YES", 0;
	for (int i = 0; i < s.size() / 2; ++i)
	{
		if (s[i] != s[s.size() - i - 1])cnt++;
	}
	if (cnt == 1 || (cnt == 0 && s.size()%2 != 0))return cout << "YES", 0;
	cout << "NO";
}
