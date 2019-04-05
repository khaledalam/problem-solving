/@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

//https://www.codechef.com/SNCKPB17/problems/SNSOCIAL
 
int n,m;
int s[505][505];
int res,mx;
 
void update(int i, int j, vector<pair<int,int>> &newEntry)
{
    if (i<0 || j<0 || i>=n || j>=m)return;
    if(s[i][j]>=mx)return;
    s[i][j]=mx;
    newEntry.push_back({i,j});
}
 
int run(vector<pair<int,int>>kList)
{
    vector<pair<int,int>>newEntry;
    for(pair<int,int> p: kList)
    {
        int i = p.first;
        int j = p.second;
        update(i-1, j-1, newEntry);
        update(i-1, j, newEntry);
        update(i-1, j+1, newEntry);
        update(i, j-1, newEntry);
        update(i, j+1, newEntry);
        update(i+1, j-1, newEntry);
        update(i+1, j, newEntry);
        update(i+1, j+1, newEntry);
    }
    if (newEntry.size() == 0) return 0;
    else return 1 + run(newEntry);
}
 
void go()
{
    vector<pair<int,int>>holder;
    for(int i=0; i<n; i++)for(int j=0; j<m; j++){
        if(s[i][j] == mx){
            holder.push_back({i,j});
        }
    }
    cout<< run(holder) << '\n';
}
    
int main() {
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
        cin>>n>>m;
        mx=-1,res = 0;
        for(int i=0; i<n; i++)for(int j=0; j<m; j++){
            cin>>s[i][j];
            mx = max(mx, s[i][j]);
        }
        go();
	}
}
 
