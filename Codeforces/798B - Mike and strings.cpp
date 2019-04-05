//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int n, res = 1e9, len;
string a[50],tmp;
map<string,bool>vis;
set<string>ok;

void run(int x)
{
	int cnt = 0; int cycle=0;
	string str1 = a[x];
	for (int i = 0; i < n; ++i)
	{
		if (i != x)
		{
			string str2 = a[i]; cycle=0;
			while (str1 != str2)
			{
				str2.push_back(str2.front());
				str2.erase(str2.begin());
				cnt++, cycle++; if(cnt>res)return;
				if(cycle > len){ puts("-1"); exit(0); }
			}
		}
	}
	res = min(res, cnt);
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i]; tmp = a[i];
		sort(tmp.begin(), tmp.end());
		ok.insert(tmp);
	}
	if(ok.size()>1)return puts("-1"),0;
	len = a[0].size();
	for (int i = 0; i < n; ++i)
	{
		if(!vis[a[i]])run(i),vis[a[i]]=true;
	}
	cout << res;
}
