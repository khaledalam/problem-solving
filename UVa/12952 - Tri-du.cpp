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

	int a, b;
	while (cin >> a >> b)
	{
		cout<<max(a, b)<<endl;
	}
}
