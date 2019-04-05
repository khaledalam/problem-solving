//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	long long tmp, cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n / 2; i++) {
		cin >> tmp;
		cnt1 += tmp;
	}

	for (int i = 0; i < n / 2; i++) {
		cin >> tmp;
		cnt2 += tmp;
	}

	cout<<abs(cnt1-cnt2);
}
