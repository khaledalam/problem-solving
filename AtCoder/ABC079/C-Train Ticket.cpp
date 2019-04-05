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

#define maxn 101010

string s;
vector<string> v;
bool vis[4] = {0};
int a, b, c, d;

void run(int h, string k)
{
	if (h == 3)
	{
		v.pb(k);
		return;
	}
	for (int i = h; i < 3; ++i)
	{
		if (!vis[i])
		{
			vis[i] = true;
			k[i] = '+';
			run(h + 1, k);
			k[i] = '-';
			run(h + 1, k);
			vis[i] = false;
		}
	}
}

void test()
{
	for (auto it : v)
	{
		int sum = a;
		sum += (it[0] == '+' ? b : -b);
		sum += (it[1] == '+' ? c : -c);
		sum += (it[2] == '+' ? d : -d);
		if (sum == 7)
		{
			cout << a << it[0] << b << it[1] << c << it[2] << d << '=' << 7
					<< endl;
			exit(0);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);

	cin >> s;
	a = s[0] - '0';
	b = s[1] - '0';
	c = s[2] - '0';
	d = s[3] - '0';

	run(0, "+++");
	test();

}

