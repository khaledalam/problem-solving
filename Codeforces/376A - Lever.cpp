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

	string s, t1, t2;
	cin >> s;
	t1 = s.substr(0, s.find('^'));
	t2 = s.substr(s.find('^') + 1);
	ll a = 0, b = 0;

	for (ll i = 0, ed = sz(t1); i < ed; ++i)
		if (isdigit(t1[i])) a += ((t1[i] - '0') * (ed - i));

	for (ll i = 0, ed = sz(t2); i < ed; ++i)
		if (isdigit(t2[i])) b += ((t2[i] - '0') * (i + 1));

	puts(a > b ? "left" : a < b ? "right" : "balance");

}
