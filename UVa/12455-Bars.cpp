#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
long long sum, target, m;
bool flag = false;

void go(int x, long long sum) {
	if (sum == target || (a[x] == target && (x>=0 && x<(int)a.size()))) {
		flag = true;
		return;
	}
	if (x >= (int)a.size())return;
	go(x+1, sum);
	go(x+1, sum + a[x+1]);
}

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> target >> m;
		a.resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> a[j];
		}
		flag = false, sum = 0, go(-1,0LL);
		puts((flag||target==0?"YES":"NO"));
	}
}
