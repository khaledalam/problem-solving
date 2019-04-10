#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e5 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
	// freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	long long a, b;
	while (cin >> a >> b)
	{
		bitset<32> aa(a);
		bitset<32> bb(b);
		bitset<32> cc(a);

		for (int i = 0; i < aa.size(); i++)
		{
			cc[i] = (aa[i] + bb[i]) % 2;
		}
		cout << cc.to_ulong() << endl;
	}
}
