//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<vector<int>> v1, v2;
bool vis[105], vis2[105];

void run(int in, int which)
{
	if (!which)//emp
	{
		vis[in] = 1;
		for (int i = 0; i < v1[in].size(); i++)
			if (!vis2[v1[in][i]]) run(v1[in][i], 1);
	}
	else
	{
		vis2[in] = 1;
		for (int i = 0; i < v2[in].size(); i++)
			if (!vis[v2[in][i]]) run(v2[in][i], 0);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	v1.resize(n + 1), v2.resize(m + 1);
	bool flag = false;
	for (int i = 1; i <= n; ++i)
	{
		int emp;
		cin >> emp;
		if (emp) flag = true;
		for (int j = 0; j < emp; ++j)
		{
			int lang;
			cin >> lang;
			v1[i].push_back(lang);
			v2[lang].push_back(i);
		}
	}
	if (!flag) return cout << n, 0;

	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			ans++;
			run(i, 0);
		}
	}
	return cout << ans - 1, 0;
}
