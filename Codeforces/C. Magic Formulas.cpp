//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

long long q, n;
map<long long, long long> memo;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		memo[i] = i ^ memo[i - 1];
	for (int i = 0; i < n; ++i)
	{
		long long tmp;
		cin >> tmp;
		q ^= tmp;
	}
	for (int i = 0; i < n; ++i)
	{
		if ((n / (i + 1)) % 2) q ^= memo[i];
		q ^= memo[n % (i + 1)];
	}
	return cout << q, 0;
}
