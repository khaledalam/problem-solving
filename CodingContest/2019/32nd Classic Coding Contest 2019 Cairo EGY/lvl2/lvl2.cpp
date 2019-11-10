#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 8 * 1e3 + 10;
const int inf = (1953125 << 9);
bool vis[maxn][maxn];

int c, r;
ll g[maxn][maxn];

bool check(int x, int y, int target) {
	if (x - 1 < 0 || y - 1 < 0)
		return true;
	if (x + 1 >= r || y + 1 >= c)
		return true;

	if (target != g[x + 1][y])
		return true;
	if (target != g[x - 1][y])
		return true;
	if (target != g[x][y + 1])
		return true;
	if (target != g[x][y - 1])
		return true;

	return false;

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	memset(vis, false, sizeof vis);
//	freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	cin >> r >> c;

	map<int, bool> ok;
	vector<ll> country;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			int x, y;
			cin >> x >> y;
			g[j][i] = y;
			if (!ok[y]) {
				ok[y] = true;
				country.push_back(y);
			}
		}
	}


//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j < c; ++j) {
//			cout << g[i][j] << " ";
//		}
//		cout << endl;
//	}
	sort(country.begin(), country.end());

	for (auto &idx : country) {

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				vis[i][j] = false;
			}
		}

		ll res = 0;

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (!vis[i][j] && g[i][j] == idx && check(i, j, idx)) {
					vis[i][j] = true;
					res++;
				}
			}
		}

//		cout << idx << " : " << res << endl;

		cout<<res<<endl;
		idx++;
	}

}
