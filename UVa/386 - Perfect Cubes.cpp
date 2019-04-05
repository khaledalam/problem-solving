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

	for (int i = 2; i <= 200; ++i)
	{
		for (int j = 2; j <= 200; ++j)
		{
			for (int k = j + 1; k <= 200; ++k)
			{
				int sum2 = (j * j * j) + (k * k * k);
				int n = (i * i * i);
				if (sum2 > n)
					break;
				int cb = cbrt(n - sum2);
				if (cb < k)
					break;
				cb = max(2, cb - 1);
				if ((cb * cb * cb) + sum2 == n)
					cout << "Cube = " << i << ", Triple = (" << j << "," << k
							<< "," << cb << ")\n";

				cb++;
				if ((cb * cb * cb) + sum2 == n)
					cout << "Cube = " << i << ", Triple = (" << j << "," << k
							<< "," << cb << ")\n";

				cb++;
				if ((cb * cb * cb) + sum2 == n)
					cout << "Cube = " << i << ", Triple = (" << j << "," << k
							<< "," << cb << ")\n";
			}
		}

	}

}
