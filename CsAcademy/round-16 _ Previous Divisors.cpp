// Ninjo ~ khaledalam.net@gmail.com
#include <bits/stdc++.h>
using namespace std;
#define sz(A)      (int)(A).size()
#define all(B)     (B).begin(),(B).end()
#define file       freopen("input.txt", "r", stdin)
#define ios        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//https://csacademy.com/contest/round-16/#task/previous-divisors

vector<int> v;

long long fun(int n) {
	v.push_back(n);
	long long tmp = 0;
	for (int j = 0; j < sz(v) - 1; ++j) {
		if (n % v[j] == 0)if(n != 0 && v[j] != 0)
			tmp++;
	}
	return tmp;
}

int main() {
//	file;
	int n, a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		
		if (a != 0) {
			cout << fun(a) << endl;
		} else {
			cout << sz(v)<<endl;
			v.push_back(-1e9);
		}
	}

}
