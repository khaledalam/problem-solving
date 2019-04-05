#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> vis;
int n, m, k;
void check(int x, int a, int b) {
	if (vis[ { a, b + 1 }] + vis[ { a + 1, b }] + vis[ { a + 1, b + 1 }] == 3) {
		cout << x;
		exit(0);
	}
	if (vis[ { a, b - 1 }] + vis[ { a + 1, b - 1 }] + vis[ { a + 1, b }] == 3) {
		cout << x;
		exit(0);
	}
	if (vis[ { a - 1, b - 1 }] + vis[ { a - 1, b }] + vis[ { a, b - 1 }] == 3) {
		cout << x;
		exit(0);
	}
	if (vis[ { a - 1, b }] + vis[ { a - 1, b + 1 }] + vis[ { a, b + 1 }] == 3) {
		cout << x;
		exit(0);
	}
}

int main() {
//	freopen("data.in", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		int a, b;
		cin >> a >> b;
		if (!vis[ { a, b }]) {
			vis[ { a, b }] = true;
			check(i, a, b);
		}
	}
	return puts("0");
}
