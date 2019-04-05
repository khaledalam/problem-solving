#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, c;
bool check(int x, int y, int z){
	if( x+y+z == a && ( x*y*z) == b  &&  ((x*x)+(y*y)+(z*z))==c ){
		if(x != y && y != z && x != z)return true;
	}
	return false;
}
int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--) {
		bool f = false;
		cin >> a >> b >> c;
		for (int i = -100; i < 100; ++i) {
			for (int j = i; j < 100; ++j) {
				int u = i + j;
					if (check(i, j, abs(a-u) )) {
						cout << i << ' ' << j << ' ' << abs(a-u) << "\n";
						f = true;
						goto out;
				}
			}
		}
		out:
		if(!f)cout<<"No solution.\n";
		continue;
	}
}
