#include <bits/stdc++.h>
using namespace std;

vector<int> v, res;
int t;
map<int, bool> mp;
void go(int x, int recent) {

	if (x == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << res[i];if(i<5)cout<<' ';
		}
		cout << endl;
		return;
	}

	for (int i = x; i < x + t - 5; ++i) {
		if (!mp[v[i]] && i>=recent) {
			mp[v[i]] = true;
			res.push_back(v[i]);
			go(x + 1,i);
			res.pop_back();
			mp[v[i]] = false;
		}
	}
}
int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	bool f=false;
	while (~scanf("%d", &t)&&t) {
		if(f)cout<<endl;
		v.clear();
		res.size();
		v.resize(t);
		for (int i = 0; i < t; ++i) {
			cin >> v[i];
		}
		go(0,0);
		f=true;
	}
}
