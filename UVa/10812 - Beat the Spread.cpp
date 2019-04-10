#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e5 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
	// freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (b > a)
		{
			cout << "impossible" << endl;
			continue;
		}
		
		int cnt = 0;
		while(true){
			int sec = a-cnt;
			if(abs(cnt - sec) == b ){
				cout << max(cnt, sec) << " " << min(cnt, sec) << endl;
				break;
			}
			cnt++;
			if(cnt > a){
				cout << "impossible" << endl;
				break;
			}
		}
		

		
	}
}
