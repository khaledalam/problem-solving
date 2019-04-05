//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
 
// https://www.codechef.com/SNCKQL17/problems/TEMPLELA

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s;
		bool f = true;
		scanf("%d",&s);
		int a[s];
		for (int i = 0; i < s; ++i) {
			scanf("%d",&a[i]);
			if(i != 0)
			{
				if(abs(a[i] - a[i-1]) != 1)f = false;
			}
			if(i <= s/2)
			{
				if(i > 0 && a[i] <= a[i-1])f = false;
			}
			else if(i > ((s+1)/2))
			{
				if(a[i] >= a[i-1])f = false;
			}
		}
		if(a[0] != 1 || a[s-1] != 1)f = false;
		if( !(s&1) ) f = false;
		puts(f?"yes":"no");
	}
 
} 
