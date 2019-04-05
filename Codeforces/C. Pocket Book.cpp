//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, arr[101][26];
	memset(arr, 0, sizeof arr);
	string s;
	cin >> a >> b;
	while (a--)
	{
		cin >> s;
		for (int f = 0; f < b; f++)
			arr[f][s[f] - 'A'] = 1;
	}
	long long ans = 1;
	for (int f = 0; f < b; f++)
	{
		int tmp = 0;
		for (int f1 = 0; f1 < 26; f1++)
			tmp += arr[f][f1];
		ans = (ans * tmp) % MOD;
	}
	cout << ans;
}
