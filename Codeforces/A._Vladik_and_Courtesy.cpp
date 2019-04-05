//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	long long a, b, st = 1;
	bool who = true;
	cin >> a >> b;
	while (true) {
		if (who) {
			if (st > a) {
				return cout << "Vladik", false;
			} else {
				a -= st;
			}
			who = !who;
		} else {
			if (st > b) {
				return cout << "Valera", false;
			} else {
				b -= st;
			}
			who = !who;
		}
		st++;
	}
}
