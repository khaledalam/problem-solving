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

#define MAXN 111
int a, b;
vector<string> g;
map<pair<int, int>, bool> vis;

map<char, pair<int, int>> dirs;

void run(int x, int y, char dir)
{

	if (x >= b || y >= a || x < 0 || y < 0) return;

//	cout << x << ' ' << y << "  : " << g[x][y] << " " << dir << endl;

	if (g[x][y] == '*')
	{
		puts("*");
		exit(false);
	}
	if (vis[ { x, y }])
	{
		puts("!");
		exit(false);
	}

	vis[ { x, y }] = true;

	run(x + dirs[dir].fi, y + dirs[dir].se, (g[x + dirs[dir].fi][y + dirs[dir].se] != '.' ? g[x + dirs[dir].fi][y + dirs[dir].se] : dir));

}

int main()
{
//	ios;
//	ifile(input.txt); //ofile(output.txt);

	cin >> a >> b;
	for (int i = 0; i < a; ++i)
	{
		string s;
		cin >> s;
		g.push_back(s);
	}

	dirs ['>'] =
	{	0,+1};
	dirs ['<'] =
	{	0,-1};
	dirs ['v'] =
	{	+1,0};
	dirs ['^'] =
	{	-1,0};

	run(0, 0, g[0][0]);
}

