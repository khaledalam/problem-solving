#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2 * 1e5 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
//	freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	int n;
	cin >> n;
	ll mi = 1e9, mx = -1;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		mi = min(x, mi);
		mx = max(x, mx);
	}
	cout << mi << " " << mx << endl;
}
