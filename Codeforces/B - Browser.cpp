#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef stringstream ss;
#define pb            push_back
#define all(x)        x.begin(),x.end()
#define sz(x)        ((int)(x.size()))
#define clr(x)        memset(x,0,sizeof x)
#define out(x)       return cout<<x,0
#define rep(i,n)     for(int i=0;i<n;i++)
// Ninjo | v0.0.3 | github.com/khaledalam/templates/tree/master/cpp
//===========================================
#define maxn 100100

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if (b == 1 && c == n)
		out(0);

	if (abs(a - b) < abs(a - c))
	{
		if(b == 1)cout << abs(a - c) + (c != n) + (b != 1 ? abs(c - b) + 1 : 0);
		else
		cout << abs(a - b) + (b != 1) + (c != n ? abs(c - b) + 1 : 0);

	} else
	{
		if(c == n)cout << abs(a - b) + (b != 1) + (c != n ? abs(c - b) + 1 : 0);
		else
		cout << abs(a - c) + (c != n) + (b != 1 ? abs(c - b) + 1 : 0);
	}
}
