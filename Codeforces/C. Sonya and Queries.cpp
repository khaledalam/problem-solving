//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

map<string, long long> mp;
int n;
string str;
char c;

void process(string s, bool op)
{
	int fIdx = 1, sz = (int) s.size();
	for (int i = s.size() - 1; i >= 0; --i)
	{
		s[i] = (((s[i] - '0') & 1) ? '1' : '0');
		if (s[i] == '1') fIdx = sz - i;
	}
	s = string(19 - sz, '0') + s;
//	cout << '>' << s << '|' << fIdx << endl;
	for (int i = fIdx; i < 19; ++i)
	{
		mp[string(s.end() - i, s.end())] += (op ? 1 : -1);
//		cout << string(s.end() - i, s.end()) << '-' << mp[string(s.end() - i, s.end())] << endl;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> str;
		if (c == '+')
		{
			process(str, true);
		}
		else if (c == '-')
		{
			process(str, false);
		}
		else
		{
			cout << mp[str] << endl;
		}
	}
}
