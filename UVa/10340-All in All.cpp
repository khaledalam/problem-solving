#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	while (cin >> a >> b && EOF) {
		int j = 0;
		for (int i = 0; i < b.size(); ++i) {
			if (b[i] == a[j]) {
				j++;
				if (j > a.size() - 1)break;
			}
		}
		puts((j > a.size() - 1 ? "Yes" : "No"));
	}
	return 0;
}
