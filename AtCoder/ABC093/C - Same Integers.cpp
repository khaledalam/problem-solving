#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 5;
 
int a[3], cnt = 0;
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
 
	for (int i = 0; i < 3; ++i)
	{
		cin >> a[i];
	}
 
	sort(a, a + 3);
	while (a[0] != a[2])
	{
		sort(a, a + 3);
		cnt++;
		if(a[1] < a[2])a[0]++,a[1]++;
		else a[0]+=2;
	}
	cout << cnt << endl;
 
}
