//KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	const int len = (int) a.size();
	for (int i = 0; i < len; ++i)
	{
		if (a[i] < b[i])
		{
			return puts("-1"), 0;
		}
	}

	puts(b.c_str());
}
