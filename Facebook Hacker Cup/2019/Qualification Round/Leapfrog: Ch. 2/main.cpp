#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e1 + 10;
const int inf = (1953125 << 9);
//bool vis[maxn];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//	memset(vis, false, sizeof vis);
	freopen("leapfrog_ch_.txt", "r", stdin);
	freopen("data.out", "w", stdout);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		string s;
		cin >> s;
		int b = 0, len = s.length();
		for (char c : s)
			b += (c == 'B');
		cout << "Case #" << tt << ": "
				<< ((b == 1 && len == 3) || (b >= 2 && b + 1 < len) ? 'Y' : 'N')
				<< endl;
	}
}
