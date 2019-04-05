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

#define MAXN 25

double a[MAXN][2];
double t, n, res;

double run(int idx, double remain)
{
//	cout << f << " --- " << c << endl;

	if (idx == n)
		return remain < 1e-9 ? 0 : 1e9;

	return min(run(idx + 1, remain),
			a[idx][1] + run(idx + 1, remain - a[idx][0]));
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);

	cin >> n;
	rep(i,n)
	{
		cin >> a[i][0] >> a[i][1];
	}
	cin >> t;
	rep(i,t)
	{
		double t1, t2;
		cin >> t1 >> t2;

		res = run(0, t1 / t2);
		if (res == 1e9)
		{
			cout << "Case " << i + 1 << ": IMPOSSIBLE\n";
			continue;
		}
		cout << "Case " << i + 1 << ": " << res << endl;
	}

}
