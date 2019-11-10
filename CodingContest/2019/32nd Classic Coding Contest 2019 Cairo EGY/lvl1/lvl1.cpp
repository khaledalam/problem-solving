#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1 * 1e3 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
//	freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	ll c, r;
	double mi = 1e9, mx = -1, sum = 0;
	cin >> c >> r;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			double x;
			cin >> x;
			sum += x;
			mi = min(mi, x);
			mx = max(mx, x);
		}
	}
	cout << fixed << mi << " " << mx << " " << floor(sum / (c * r)) << endl;

}
