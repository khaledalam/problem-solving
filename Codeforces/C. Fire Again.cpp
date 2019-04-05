//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
#define MAX 2017
int n, m, q, a, b;
bool vis[MAX][MAX];
int x[] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int y[] = { 0, 1, 0, -1, -1, 1, 1, -1 };
queue<pair<int, int>> v;

//http://codeforces.com/contest/35/problem/C


void run()
{
	pair<int, int> it = v.front();
	while (v.size())
	{
		it = v.front();
		v.pop();
		for (int k = 0; k < 4; ++k)
		{
			int xx = x[k] + it.first;
			int yy = y[k] + it.second;
			if (xx > 0 && xx <= n && yy > 0 && yy <= m)
			{
				if (!vis[xx][yy])
				{
					vis[xx][yy] = true;
					v.push( { xx, yy });
				}
			}
		}
	}
	cout << it.first << ' ' << it.second;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, 0, sizeof vis);
	cin >> n >> m >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> a >> b;
		vis[a][b] = true;
		v.push( { a, b });
	}
	run();
}
