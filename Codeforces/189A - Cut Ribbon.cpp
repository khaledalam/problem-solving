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

#define maxn 5000
int n, freq[3];

//53 10 11 23

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);

	cin >> n;
	rep(i,3)
		cin >> freq[i];

	sort(freq, freq + 3);

	int mx = 1;
	for (int i = n; i >= 0; --i)
	{
		for (int j = 0; j <= n - freq[0] * i; ++j)
		{
			int k = (n - (freq[0] * i + freq[1] * j)) / freq[2];
			if (k < 0)
				continue;
			if ((freq[0] * i + freq[1] * j + freq[2] * k) == n)
			{
//				cout << i << " " << j << " " << k << endl;
				mx = max(mx, i + j + k);
			}
		}
	}
	out(mx);
}
