//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
long long n;
char c;
string res, digit[] = {"", "", "2", "3", "322", "5", "53", "7", "7222", "7332"};

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		res += digit[c-'0'];
	}
	sort(res.rbegin(), res.rend());
	cout<<res;
}
