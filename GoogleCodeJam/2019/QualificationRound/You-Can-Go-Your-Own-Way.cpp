#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5 * 1e4 + 10;
bool vis[maxn];
const int inf = (1953125 << 9);

string bookedPath,res="",path="";
string grid[maxn];
int n;

void run(int x, int y, int step, char dir){

	if(dir != '#')
	if(bookedPath[step-1] ==  dir)return;
	if(x>=n || y >=n)return;

	// cout<<res<<endl;

	if(step == 2*n-2){
		path = res;
		return;
	}
	
	if(!vis[step]){
		vis[step] = true;
		res.push_back('E');
		run(x,y+1,step+1,'E');
		res.pop_back();
		
		res.push_back('S');
		run(x+1,y,step+1,'S');
		res.pop_back();
	}
}

int main()
{
	// ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
	// freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin>>n>>bookedPath;
		path = res = "";
		run(0,0,0,'#');
		memset(vis, false, sizeof vis);
		cout << "Case #" << tt << ": " << path << endl;
			
	}
	return 0;
}

