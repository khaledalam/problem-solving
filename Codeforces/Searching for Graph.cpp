//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int n, q;
long long int arr[300001];
long long int arr2[300001];
long long int diff[300002];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, p;
		cin >> n >> p;
		int req = 2 * n + p;
		for (int i = 1; i <= n && req; i++)
		{
			for (int j = i + 1; j <= n && req; j++)
			{
				cout << i << ' ' << j << '\n';
				req--;
			}
		}
	}
}

