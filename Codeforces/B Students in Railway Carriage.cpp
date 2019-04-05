#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 100;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	int n, a, b, cnt = 0, i;
	string s;
	cin >> n >> a >> b >> s;
	vector<int> dots;
	int start = 0;
	for (i = 0; i < (int) s.size(); ++i)
	{
		if (s[i] == '*')
		{
			if (start != i) dots.push_back(i - start);
			start = i + 1;
		}
	}
	if (start != i)dots.push_back(i - start);

	for (int it : dots)
	{
		int put1 = it / 2;
		int put2 = it - (it >> 1);
		if (a > b) swap(put1, put2);
		cnt += min(a, put1);
		cnt += min(b, put2);
		a -= min(a, put1);
		b -= min(b, put2);
	}
	cout << cnt << endl;

}
