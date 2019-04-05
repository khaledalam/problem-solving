//@author Khaled Alam(Ninjo) ~ KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
// Template(v0.0.1)  |  Github.com/khaledalam/templates/tree/master/cpp
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
#define val(x)       cerr<<"[l#: "<<__LINE__<<"] "<< " "<<#x<<" = "<<x<<'\n'
//##########################################################################

#define MAXN 210

template<class T>
bool notNum(T x)
{
	ss a;
	a << x;
	string s;
	a >> s;
	for (char c : s)
	{
		if (!isdigit(c)) return true;
	}
	return false;
}

string s, skip, key, c1, c2;
map<string, int> ma;
int last = 0, tmp;

int main()
{
//	ios;
//	ifile(input.txt); //ofile(output.txt);

	while (getline(cin, s))
	{
		ss st;
		st << s;
		st >> key;
		st >> skip;

		if (find(all(s), '+') != s.end()) //has +
		{
			st >> c1;
			st >> skip;
			st >> c2;

			if (notNum(c1))
			{
				ma[key] += ma[c1];
			}
			else
			{
				ma[key] += stoi(c1);
			}
			if (notNum(c2))
			{
				ma[key] += ma[c2];
			}
			else
			{
				ma[key] += stoi(c2);
			}
		}
		else
		{
			st >> tmp;
			ma[key] += tmp;
		}

		last = ma[key];
	}
	cout << last << endl;
}

