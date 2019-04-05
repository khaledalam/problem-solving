#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int n,zeros=0,sum=0;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		if(a[i] == 0)zeros++;
		sum+=a[i];
	}
	if(zeros==n)return puts("NO"), 0;
	puts("YES");
	if(sum !=0)return cout<<1 <<'\n'<<1<<' '<<n, 0;
	int k=1,i=0;
	while(!sum){
		sum-=a[i++];
		if(!sum)k++;
	}
	cout<<2<<'\n'<<1<<' '<<k<<'\n'<<k+1<<' '<<n;
}
