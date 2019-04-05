//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s1 >> s2;
	if (s1.size() != s2.size()) return puts("NO"), 0;
	if (s1 == s2) return puts("YES"), 0;
	return cout << (count(s1.begin(), s1.end(), '1') > 0 && count(s2.begin(), s2.end(), '1') > 0 
			? "YES\n" 
			: "NO\n"), 0;
}
