#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1 * 1e5 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

const ll MOD = 1000000007;
ll dp[maxn];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, -1, sizeof vis);
//	freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	int t, k;
	cin >> t >> k;

	vector<ll> comRange;
	comRange.push_back(dp[0] = 1);

	for (ll i = 1; i < maxn; ++i) {
		dp[i] += dp[i - 1] + MOD;
		dp[i] %= MOD;

		if (i >= k) {
			dp[i] += dp[i - k] + MOD;
			dp[i] %= MOD;
		}

		comRange.push_back((comRange.back() + dp[i] + MOD) % MOD);
	}

	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;
		cout << ((comRange[b] - comRange[a - 1]) + MOD) % MOD << endl;
	}
}
