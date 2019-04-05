#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	while (cin >> t && EOF) {
		int a[t], money;
		for (int i = 0; i < t; ++i) {
			cin >> a[i];
		}
		cin >> money;
		sort(a, a + t);
		pair<long long, long long> res = { a[0], a[1] };
		long long diff = 1e9;

		for (int i = 0; i < t; ++i) {
			long long findOther = abs(money - a[i]);
			if (binary_search(a, a + t, findOther)) {
				if (findOther == a[i]) {
					int c = count(a, a + t, findOther);
					if (c < 2)
						continue;
				}
				long long currentDiff = abs(a[i] - findOther);
				if ((currentDiff < diff)) {
					diff = currentDiff;
					res.first = a[i];
					res.second = findOther;
				}
			}
		}
		cout << "Peter should buy books whose prices are " << res.first
				<< " and " << res.second << ".\n\n";
	}
}
