#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	long long a[n], b[n] = { 0 };
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long holder = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		b[i] += holder;
		if (a[i] != b[i]) {
			holder += a[i] - b[i];
			cnt += abs(a[i] - b[i]);
		}
	}
	cout << cnt;
}
