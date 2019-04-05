#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int a[t];
	for (int i = 0; i < t; ++i) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	int tmp;
	for (int i = 0; i < q; ++i) {
		cin >> tmp;

		auto lo = lower_bound(a, a + t, tmp)-1;
		auto hi = upper_bound(a, a + t, tmp);

//		cout<<*lo<<' '<<*hi<<endl;

		bool f = binary_search(a, a + t, *(lo));
		bool l = binary_search(a, a + t, *(hi));

		if (f) {
			if (l) cout << *lo << ' ' << *hi << '\n';
			else cout << *lo << " X\n";
		} else {
			if (l)cout << "X " << *hi << '\n';
			else cout << "X X\n";
		}
	}
}
