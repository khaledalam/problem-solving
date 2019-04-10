#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e5 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

int main()
{
	// ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// memset(vis, false, sizeof vis);
	// freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	double a, b, c;
	while (cin >> a >> b >> c)
	{
		double all = a + b;
		double rem = all - c - 1;
		printf("%.5lf\n", (a / all) * (b / rem) + (b / all) * ((b - 1) / rem));
	}
}
