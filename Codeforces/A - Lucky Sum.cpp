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

#define maxn 10
ll l, r;
vector<ll> v;

void init(ll num)
{
	if (num > 1e10)
		return;
//	cout << num << endl;
	if (num >= l)
		v.pb(num);
	init(num * 10 + 4LL);
	init(num * 10 + 7LL);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);

	cin >> l >> r;
	init(0);
	sort(all(v));
	ll res = 0, prevv = l;

//	rep(i,20)cout << v[i] << ' ';cout << endl;

//	ll ee = upper_bound(all(v), r) - v.begin();
//	cout << ee << endl;

	for (ll i = 0; prevv <= r; ++i)
	{
//		cout<<"NO: "<<v[i]<<" << "<<prevv<<endl;
//		cout<<"MI: "<<min(v[i], r)<<" << "<<prevv<<endl;
		ll times = min(v[i], r) - prevv + 1;
		res += times * v[i];
		prevv = v[i] + 1;
	}
	cout << res << endl;

}
