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

	stringstream ss;
	string s;
	while (getline(cin, s))
	{
		ss.clear();
		ss << s;

		int a[3][3];
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				ss >> a[j][i];
			}
		}
		int mn = inf, b1 = 0, b2 = 0, b3 = 0;
		string res = "BCG";
		auto structString = [](int i, int j)
		{
			string X = "BCG";
			if(!i)
			{
				X[0] = 'B';
				if(j == 1)X[1] = 'G', X[2]='C';
				else X[1] = 'C', X[2]='G';
			}
			else if(i == 1)
			{
				X[0] = 'G';
				if(!j)X[1] = 'B', X[2]='C';
				else X[1] = 'C', X[2]='B';
			}
			else
			{
				X[0] = 'C';
				if(!j)X[1] = 'B', X[2]='G';
				else X[1] = 'G', X[2]='B';
			}
			return X;
		};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					if (i != j && j != k && i != k)
					{
						b1 = b2 = b3 = 0;
						for (int x = 0; x < 3; ++x)
							if (x != i)
								b1 += a[x][0];
						for (int y = 0; y < 3; ++y)
							if (y != j)
								b2 += a[y][1];
						for (int z = 0; z < 3; ++z)
							if (z != k)
								b3 += a[z][2];

//						cout<<i<<' '<<j<<' '<<k<<": "<<b1<<' '<<b2<< " " <<b3<<endl;
						if (b1 + b2 + b3 < mn)
						{
							mn = b1 + b2 + b3;
							res = structString(i, j);
						} else if (b1 + b2 + b3 == mn)
						{
							if (structString(i, j) < res)
							{
								mn = b1 + b2 + b3;
								res = structString(i, j);
							}
						}

					}
				}
			}
		}
		cout << res << ' ' << mn << endl;

	}
}
