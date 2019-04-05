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

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		string s;
		int D, i, count = 0, total = 0, flag = 1, len, weg[1000] = { 0 }, con = 0, temp = 0, j;
		cin >> D >> s;
		len = s.length();
		for (i = 0; i < len; i++)
		{
			if (s[i] == 'S')
			{
				count++;
				total = total + flag;
				weg[i] = flag;

			} else
				flag = flag * 2;

		}
		if (count > D)
			cout << "Case #" << tt << ": " << "IMPOSSIBLE" << endl;
		else if (count == 0 || total <= D)
			cout << "Case #" << tt << ": " << "0" << endl;
		else
		{

			for (i = len - 2; i >= 0; i--)
			{
				if (s[i] == 'C' && s[i + 1] == 'S')
				{
					total = total - weg[i + 1] / 2;
					weg[i] = weg[i + 1] / 2;
					weg[i + 1] = 0;
					s[i] = 'S';
					s[i + 1] = 'C';
					con++;
					if (total <= D)
					{
						cout << "Case #" << tt << ": " << con << endl;
						break;
					}

					for (j = i + 1; j <= len - 2; j++)
					{
						if (s[j] == 'C' && s[j + 1] == 'S')
						{
							total = total - weg[j + 1] / 2;
							weg[j] = weg[j + 1] / 2;
							weg[j + 1] = 0;
							s[j] = 'S';
							s[j + 1] = 'C';
							con++;
							if (total <= D)
							{
								cout << "Case #" << tt << ": " << con << endl;
								temp++;
								break;
							}
						}
					}
					if (temp == 1)
						break;
				}
			}
		}
	}
}
