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

#define maxn 200101

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);

	int n, ans = 0;
	char a, b, c, d, aa, bb, cc, dd;
	stack<char> st;
	cin >> n;

	while (n--)
	{
		cin >> a >> b >> c >> d;

		if (st.empty())
		{
			st.push('F'); st.push('A'); st.push('C'); st.push('E');
		}

		dd = st.top();st.pop();
		cc = st.top();st.pop();
		bb = st.top();st.pop();
		aa = st.top();st.pop();

		if (dd == a && cc == b && bb == c && aa == d) ans++;
		else
		{
			st.push(aa);
			st.push(bb);
			st.push(cc);
			st.push(dd);

			st.push(a);
			st.push(b);
			st.push(c);
			st.push(d);
		}
	}
	cout << ans << endl;

}

