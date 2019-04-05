//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,cnt = 0;
	scanf("%d", &n);
	char s[2],prev;
	for(int i=0; i<n; i++)
	{
		scanf("%s",s);
		if(i==0)
		{
			prev = s[1];
			continue;
		}
		if(s[0] != prev)cnt++;
		prev = s[1];
	}
	cout<<cnt<<'\n';
}
