#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = (1953125 << 9);
const ll maxn = 1 * 1e5 + 100;

int arr[maxn];
vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		int n;
		vi.clear();
		bool k = true;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i], vi.push_back(arr[i]);

		sort(vi.begin(), vi.end());
		while (true)
		{
			bool ok = false;
			for (int i = 0; i < n - 2; ++i)
				if (arr[i] > arr[i + 2])
				{
					ok = true;
					swap(arr[i], arr[i + 2]);
				}
			if (!ok)
				break;
		}
		for (int i = 0; i < n; ++i)
			if (arr[i] != vi[i])
			{
				cout << "Case #" << tt << ": " << i << endl;
				k = false;
				break;
			}
		if (k)
			cout << "Case #" << tt << ": OK" << endl;
	}
}

