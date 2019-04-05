#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n, cnt = 0;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s[0] == 'I') {
			cnt += 20;
		} else if (s[0] == 'C') {
			cnt += 6;
		} else if (s[0] == 'T') {
			cnt += 4;
		} else if (s[0] == 'D') {
			cnt += 12;
		} else {
			cnt += 8;
		}
	}
	cout << cnt;
}
