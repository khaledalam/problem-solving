//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stringstream ss;
typedef pair<int, int> pii;
//#########################
#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define out(x)       return cout<<x,0
#define all(x)       x.begin(),x.end()
#define sz(x)        ((int)(x.size()))
#define clr(x)       memset(x,0,sizeof x)
#define rep(i,n)     for(int i=0;i<n;i++)
#define debug(x)     cerr<<"[l#: "<<__LINE__<<"] "<<#x<<" = "<<x<<endl
// v0.0.2 | Github.com/khaledalam/templates/tree/master/cpp
//##########################################################################

#define MAXN 100100

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);

	int n, m, prev = 1;
	cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		sum += (b - a + 1);
		if (!i) sum += ((a - 1) % m);
		else sum += ((a - prev - 1) % m);
		prev = b;
	}
	cout << sum << endl;
}
