//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

vector<int> fact;
int n, m, k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	m = n;
	if (k == 1)return cout << n, 0;
	for (int i = 2; i * i <= m; ++i)
	{
		while (m % i == 0)fact.push_back(i), m /= i;
	}
	if(m>1)fact.push_back(m);
	if(k>(int)fact.size())return puts("-1"), 0;
	for (int i = 0; i < k - 1; ++i, cout << ' ')cout << fact[i];
	cout << accumulate(fact.begin()+k-1, fact.end(), 1, multiplies<int>());
}
