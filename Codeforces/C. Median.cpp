//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

//http://codeforces.com/problemset/problem/166/C
#define MAX 505
int n, target, idx, tmp;
vector<int> s;

vector<int>::iterator insert_sorted(vector<int> & vec, int const& item)
{
	return vec.insert(upper_bound(vec.begin(), vec.end(), item), item);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> target;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		s.push_back(tmp);
	}
	sort(s.begin(), s.end());
	idx = ((n + 1) / 2)-1;
	if (s[idx] == target) return puts("0"), 0;

	int cnt = 0;
	while (true)
	{
		cnt++;
		insert_sorted(s, target);
//		for(auto it: s)cout<<it<<' ';cout<<endl;
		idx = ((n + cnt + 1) / 2)-1;
		if (s[idx] == target) return cout << cnt, 0;
	}

}
