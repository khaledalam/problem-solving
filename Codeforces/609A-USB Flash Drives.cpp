#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t, n, m;
	priority_queue<int> q;
	cin >> n >> m;
	while (n--) {
		cin >> t;q.push(t);
	}
	int cnt = 0;
	while (!q.empty()) {
		if (m < 1)return cout << cnt, 0;
		m -= q.top(), q.pop(),cnt++;
	}
	cout<<cnt;
}
