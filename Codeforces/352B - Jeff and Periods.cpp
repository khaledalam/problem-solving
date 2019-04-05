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

#define maxn 100100
bool vis[maxn];

struct p {
	int prevIdx;
	int diff;
	bool ok;
	p()
	{
		ok = true;
		prevIdx = diff = -1;
	}
};
int a[maxn];
p s[maxn];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	int cnt = 0;
	rep(i,n)
	{
		cin >> a[i];
		bool f = vis[a[i]];
		vis[a[i]] = true;
		if (s[a[i]].prevIdx == -1)
		{
			s[a[i]].prevIdx = i;
			s[a[i]].diff = 0;
			if(!f)cnt++;
			continue;
		}
		if (!s[a[i]].diff)
		{
			s[a[i]].diff = i - s[a[i]].prevIdx;
			s[a[i]].prevIdx = i;
			continue;
		}
		if (s[a[i]].diff != (i - s[a[i]].prevIdx))
		{
			if (s[a[i]].ok) cnt--;
			s[a[i]].ok = false;
		}
		s[a[i]].prevIdx = i;
	}
	cout << cnt << endl;

	rep(i,maxn)
	{
		if (vis[i] && s[i].ok)
		{
			cout << i << ' ' << s[i].diff << endl;
		}
	}
}

