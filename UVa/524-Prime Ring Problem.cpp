#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int T;
bool vis[17];

bool prime(int k) {
	if (k == 1 || k == 2)return true;
	for (int i = 2; i < k; ++i) {
		if (k % i == 0)return false;
	}
	return true;
}

void check(int n) {
	if ((v.size() == n) && prime(v.front() + v.back())) {
		cout << v[0];
		for (int i = 1; i < v.size(); i++)cout << ' ' << v[i];
		cout << "\n";
	}

	for (int j = 2; j < T + 1; j++) {
		if (prime(v.back() + j) && !vis[j]) {
			v.push_back(j);
			vis[j] = 1;
			check(n);
			vis[j] = 0;
			v.pop_back();
		}
	}
}

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	int n = 1;
	bool f = false;
	while (cin >> T) {
		if(f)cout<<"\n";
		v.clear();
		memset(vis, 0, sizeof vis);
		vis[1] = 1;
		v.push_back(1);
		cout << "Case " << n << ":\n";
		check(T);
		f=true, n++;
	}
}

