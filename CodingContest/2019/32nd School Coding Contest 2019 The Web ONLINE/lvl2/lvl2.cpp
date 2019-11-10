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
	int a[n];
	int b[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	b[0] = 0;
	int idx = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1])
			b[i] = idx;
		else {
			b[i] = idx = i;
		}
	}
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		mp[b[i]]++;
	}
	int mx = 1;
	int residx = 0;
	int rescnt = 1;
	for (auto &it : mp) {
		if (it.second > mx) {
			residx = it.first;
			mx = rescnt = it.second;
		}
	}
	cout << residx << " " << mx << endl;
}
