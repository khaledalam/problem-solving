#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 5;

const ll px = 1e9;

int main()
{
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("input.txt", "w", stdout);

	srand(time(NULL));

	for (int i = 0; i < 1000; ++i)
	{
		int mx = rand() % maxn + 1;
		int mx2 = rand() % maxn + 1;
		
//		cout << mx << " " << mx2 << endl;
		
		for (int i = 0; i < mx; ++i)
		{
			cout << (rand() % px + 1) << ' ';
		}
		cout << endl;
	}
}
