//@author Khaled Alam(Ninjo) ~ KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
// Template(v0.0.1)  |    Github.com/khaledalam/templates/cpp
typedef long long ll;
typedef vector<int> vi;
typedef stringstream ss;
typedef pair<int, int> pii;
//#########################
#define endl         '\n'
#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define out(x)z      return cout<<x,0
#define all(x)       x.begin(),x.end()
#define sz (x)       ((int)(x.size()))
#define clr(x)       memset(x,0,sizeof x)
#define rep(i,n)     for(int i=0;i<n;i++)
#define ifile(x)     freopen(#x,"r",stdin)
#define ofile(x)     freopen(#x,"w",stdout)
#define pin0         size_t _A = time(NULL)
#define pin1         fprintf(stderr,"time: %.2fs",(float)time(NULL)-_A)
#define foreach(i,t) for(decltype(t.begin()) i=t.begin();i!=t.end();i++)
#define ios          ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define val(x)       cerr<<"[l#: "<<__LINE__<<"] "<< " "<<#x<<" = "<<x<<'\n'
//#########################################################################

int main()
{
//	ios;
//	ifile(input.txt); //ofile(output.txt);
	int a, b, c;
	while (cin >> a >> b >> c && EOF)
	{
		if (!(a + b + c) || (a + b + c) == 3)
		{
			puts("*");
			continue;
		}
		if (a != b && a != c) puts("A");
		else if (c != b && c != a) puts("C");
		else puts("B");
	}
}

