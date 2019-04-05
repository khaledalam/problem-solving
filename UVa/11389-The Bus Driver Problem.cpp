#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n, m, per;
	while (cin >> n >> m >> per && n && m && per) {
		int a[n], b[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		sort(a, a + n), sort(b, b + n);
		long long res = 0;
		for (int i = 0; i < n; ++i) {
			long long tmp = a[i] + b[n - i - 1];
			res += (tmp > m ? (tmp - m) * per : 0);
		}
		cout << res <<endl;
	}
}

