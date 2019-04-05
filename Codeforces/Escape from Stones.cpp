//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;
	list<int> res;
	res.push_front(1);
	auto x = res.begin();
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i - 1] == 'l')
		{
			x = res.insert(x, i + 1);
		}
		else
		{
			x++;
			x = res.insert(x, i + 1);
		}
	}
	for (auto it : res)
		cout << it << '\n';
}
