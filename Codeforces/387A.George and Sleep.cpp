#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a, b, x, y;
	char c;
	cin >> a >> c >> b >> x >> c >> y;

	b -= y;
	if (b < 0)b += 60, a--;
	a -= x;
	if (a < 0)a += 24;

	if (a < 10)cout << 0;
	cout << a << ":";
	if (b < 10)cout << 0;
	cout << b;
}
