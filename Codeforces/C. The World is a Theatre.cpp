//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

long long ncr(int n, int r)
{
	long long ret = 1;
	for (int j = 1; j <= r; j++, n--)
	{
		ret *= n;
		ret /= j;
	}
	return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	long long n, m, t;
	cin >> n >> m >> t;

	long long ans = 0;
	int cnt_b = 4;
	int cnt_g = t - 4;

	while (cnt_b <= n && cnt_g >= 1)
	{
		ans += (ncr(n, cnt_b) * ncr(m, cnt_g));
		cnt_b++;
		cnt_g--;
	}
	cout << ans;
}

