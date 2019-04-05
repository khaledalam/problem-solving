//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
 
int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		map<int, bool> mp;
		for (int i = 0; i < b; ++i) {
			int t1, t2;
			cin >> t1 >> t2;
			mp[t1] = mp[t2] = true;
		}
		int no = 0;
		for (int i = 1; i <= a; ++i) {
			if (!mp[i])no++;
		}
		puts(no % 2 == 0 ? "yes" : "no");
	}
 
}
