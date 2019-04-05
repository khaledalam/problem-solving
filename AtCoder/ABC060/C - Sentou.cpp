//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n,t,cnt=0,tmp,prev;
	cin>>n>>t;
	for (int i = 0; i < n; ++i) {
		cin>>tmp;
		if(!i){
			prev = tmp;
			continue;
		}
		cnt += min(t, tmp - prev);
		prev = tmp;
	}
	cout<<cnt+t;
}
