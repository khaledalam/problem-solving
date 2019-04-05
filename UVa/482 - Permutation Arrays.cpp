//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		stringstream ss1, ss2;
		string s1, s2, st, val;
		int idx,cnt=0;
		cin >> st;
		getline(cin, s1);
		getline(cin, s2);
		s1 = st + ' ' + s1;
//		cout<<s1<< " | " << s2<<endl;
		ss1 << s1, ss2 << s2;
		map<int, string> mp;
		while (ss1 >> idx)
		{
			ss2 >> val;
			mp[idx - 1] = val;
			cnt++;
		}
		for (int i = 0; i < cnt; ++i)
		{
			cout << mp[i] << endl;
		}
		if(t)cout << endl;

	}
}
