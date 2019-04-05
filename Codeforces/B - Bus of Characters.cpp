#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb       push_back
#define sz(x)    ((int)(x.size()))
#define all(x)   x.begin(),x.end()
#define clr(x)   memset(x,0,sizeof x)
const int inf = (1953125 << 9);
const int maxn = 1 * 1e5 + 5;

struct str
{
	int val, idx;
	int cnt = 2;
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	deque<str> w(n);
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> w[i].val;
		w[i].idx = i;
	}
	sort(w.begin(), w.end(), [](str &a, str &b)
	{
		return a.val < b.val;
	});
	cin >> s;
	set<pair<int,int>> alone;
	for (int i = 0; i < n * 2; ++i)
	{
		if (s[i] == '0')
		{
			if (w.front().cnt <= 0)
				w.pop_front();
			cout << w.front().idx + 1 << ' ';
			w.front().cnt--;
			if (w.front().cnt == 1)
			{
				alone.insert({w.front().val * -1, w.front().idx+1});
			}
			w.pop_front();
		} else
		{
			cout << (*(alone.begin())).second << ' ';
			alone.erase(alone.begin());
		}
	}
}
