// Ninjo ~ khaledalam.net@gmail.com
#include <bits/stdc++.h>

using namespace std;
#define sz(A)      (int)(A).size()
#define all(B)     (B).begin(),(B).end()
#define file       freopen("input.txt", "r", stdin)
#define ios        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
//	file;
	string s;
	getline(cin, s);
	replace(all(s), ',', ' ');
	stringstream ss;
	ss << s;
	string tmp;
	set<int> sot;
	while (ss >> tmp) {
		int y = stoi(tmp);
		sot.insert(y);
	}
	int u = 0, prev;
	bool f = 0;
	for (auto it : sot) {
		if (u == 0) {
			cout << it;
			prev = it;
		} else {
			if (it == prev + 1) {
				prev = it;
				f = 1;
			} else {
				if (f == 1) {
					f = 0;
					cout << "-" << prev << "," << it;
				} else {
					cout << "," << it;
				}
				prev = it;
			}
		}
		u++;
		if (u == sz(sot)) {
			if (f == 1) {
				cout << "-" << prev;
			}
		}
	}
}
