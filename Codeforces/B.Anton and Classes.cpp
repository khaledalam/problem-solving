#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,m,l1=1e9,h1=-1,l2=-1,h2=1e9;
	cin>>n;
	long long a[n][2];
	for (int i = 0; i < n; ++i) {
		cin>>a[i][0]>>a[i][1];
		l1 = min(l1, a[i][1]);
		l2 = max(l2, a[i][0]);
	}
	cin>>m;
	long long b[m][2];
	for (int i = 0; i < m; ++i) {
		cin>>b[i][0]>>b[i][1];
		h1 = max(h1, b[i][0]);
		h2 = min(h2, b[i][1]);
	}
	long long res = max(0LL, h1-l1);
	res = max(0LL, max(res, l2-h2 ));
	cout<<res;
}
