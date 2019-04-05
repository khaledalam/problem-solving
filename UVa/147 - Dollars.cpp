//@author Khaled Alam(Ninjo) ~ KhaledAlam.net
#include <bits/stdc++.h>
#include<iomanip>
using namespace std;
// v0.0.1  |  Github.com/khaledalam/templates/tree/master/cpp
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
#define ifile(x)     freopen(#x,"r",stdin)
#define ofile(x)     freopen(#x,"w",stdout)
#define pin0(x)      size_t x = time(NULL)
#define pin1(x)      fprintf(stderr,"time: %.2fs\n",(float)time(NULL)-x)
#define foreach(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();i++)
#define ios          ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define val(x)       cerr<<"[l#: "<<__LINE__<<"] "<< " "<<#x<<" = "<<x<<endl
//##########################################################################

#define maxn 30010
int coins[] =
{ 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

ll table[maxn];

void ways()
{
	for (int i = 0; i < 11; ++i)
	{
		for (int j = coins[i]; j <= maxn; j += 5)
		{
			table[j] += table[j - coins[i]];
		}
	}
}

int main()
{
	ios;
//	ifile(input.txt); //ofile(output.txt);
	string s,old;
	clr(table);
	table[0] = 1;
	ways();
	while(cin>>s)
	{
		if(s == "0.00")return 0;
		old = s;
		s.erase(find(all(s),'.'));
		cout<<setw(6)<<right<<old<<setw(17)<<right<<table[stoi(s)]<<endl;
	}
}
