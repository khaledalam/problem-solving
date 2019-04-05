//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
//http://codeforces.com/contest/363/problem/C
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s, ret = "";
	map<char, int> mp;
	char prev;
	cin >> s;
	ret.push_back(s[0]);
	mp[s[0]]++, prev = s[0];
	for (int i = 1; i < (int)s.size(); ++i)
	{
		if(s[i] != prev)mp[s[i]]=0;
		mp[s[i]]++;
		if (mp[s[i]] > 2) continue;
		ret.push_back(s[i]);
		prev = s[i];
	}
	int idx = 1;
	re: for (int i = idx; i < (int)ret.size()-2; ++i)
	{
		if (ret[i-1] == ret[i] && ret[i+1] == ret[i + 2])
		{
			ret.erase(ret.begin() + i + 2);
			idx = max(1, i-2);
			goto re;
		}
	}
	cout << ret;
}
