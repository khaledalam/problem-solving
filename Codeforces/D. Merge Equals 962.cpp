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

	int n;
	cin >> n;
	map<ll, set<ll>> process;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		process[x].insert(i);
	}

	for (auto &it : process)
	{
		while (it.second.size() > 1)
		{
			it.second.erase(it.second.begin());
			process[it.first * 2].insert(*it.second.begin());
			it.second.erase(it.second.begin());
		}
	}
	vector<pair<ll, ll>> sorter;
	for (auto it : process)
		if (it.second.size())
			sorter.push_back( { *it.second.begin(), it.first });

	sort(sorter.begin(), sorter.end());

	cout << sorter.size() << endl;
	for (auto it : sorter)
		cout << it.second << " ";

}
