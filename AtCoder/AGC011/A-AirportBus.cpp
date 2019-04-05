#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n, c, k;
	cin >> n >> c >> k;
	long long a[n];
	for (long long i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int cnt = 0;
	for (long long i = 0; i < n; ++i) {
		long long it = i + 1;
		long long items = 1;
		while (abs(a[i] - a[it]) <= k && items++ < c && it < n) {
			it++;
		}
		i = it-1;
		cnt++;
	}

	cout << cnt  << endl;

}

/*
 * 2
 * 6
 * 6
 * 8
 * 10
 */
