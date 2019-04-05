#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 5;
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
 
	ll a, b, c, aa, bb;
	cin >> a >> b >> c;
	aa = a, bb = b;
 
	if (a == b)
		return cout << a, 0;
	set<ll> ss;
 
	for (int i = 0; i < min(c, abs(aa - bb)); ++i)
	{
		ss.insert(a++);
	}
	for (int i = 0; i < min(c, abs(aa - bb)); ++i)
	{
		ss.insert(b--);
	}
	for (auto it : ss)
		cout << it << endl;
 
}
