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

	int n, m, k;
	cin >> n >> m >> k;
	int a[n];
	rep(i,n)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	int sum = 0;
	if (k >= m) out(0);
	for (int i = 0; i < n; ++i)
	{
		k--;
		sum += a[i] - (k < 0 ? 1 : 0);
//		cout << sum << endl;
		if (sum + (k > 0 ? k : 0) >= m)
		{
			out(i + 1);
		}
	}
	out(-1);

}
