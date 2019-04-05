//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

long long n, cnt = 1, res = 2e9,sz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	string t = to_string(n);
	sz = t.size();
	if(sz==1)return cout<<1,0;
	for (int i = 1; i < sz; ++i) {
		t[i]='0';
	}
	if(t[0] == '9'){
		t[0] = '0';
		t = '1'+ t;
	}
	else t[0]++;
	return cout<<abs(stoll(t)-n),0;
}
