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
	//	freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	int a[n];
	rep(i,n)
		cin >> a[i];
	rep(i,n)
	{
		rep(j,n)
		{
			rep(k,n)
			{
				if (a[i] == a[j] + a[k] && (i ^ j) && (j ^ k) && (i ^ k))
					return cout << i+1 << " " << j+1 << " " << k+1 << endl, 0;
			}
		}
	}
	out(-1);

}
