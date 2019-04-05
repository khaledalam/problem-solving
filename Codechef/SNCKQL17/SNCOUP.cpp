//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
//https://www.codechef.com/SNCKPB17/problems/SNCOUP
int t,n;
string s[2];
vector<int>g[2];
 
void run()
{
    int ct = 0, len = g[1].size();
    bool vta1 = false, vta2 = false, fl = false, ht = false;
    for(int i=0; i<len; i++){
        if ( (vta1 && g[0][i]==1) || (vta2 && g[1][i]==1) ){
            ct+=1;
            fl = true;
            
            if(g[0][i]==1)vta1 = true;
            else vta1 = false;
            
            if(g[1][i]==1)vta2 = true;
            else vta2 = false;
            
            if(g[0][i]==1 && g[1][i]==1 && !(ht)){
                ct+=1;
                ht = true;
            }
        }
        else{
        	// puts("here");
            if ( !(g[0][i]==0 && g[1][i]==0 ) ){
                if(fl){
                	// puts("here 1");
                    if (!ht){
                        ct+=1;
                        ht = true;
                    }
                    if(g[0][i]==1)vta1 = true;
                    if(g[1][i]==1)vta2 = true;
                }
                else{
                	// puts("here 2");
                    if(g[0][i]==1 and g[1][i]==1){
                        ct+=1;
                        ht = true;
                    }
                    fl = true;
                    if(g[0][i]==1)vta1 = true;
                    if(g[1][i]==1)vta2 = true;
                }
            }
        }
    }
    cout<<ct<<'\n';
}
 
int main() {
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin>>t;
	while(t--)
	{
        cin>>n>>s[0]>>s[1];
        // cout<<s[0]<<endl<<s[1]<<endl;
        g[0].resize(n);
        g[1].resize(n);
        for(int i=0; i<2; i++)
        {   
            for(int j=0; j<n; j++)
            {
                g[i][j] = (s[i][j] == '*');
            }
        }
        // for(int it : g[1])cout<<it<<' ';
        // for(int k=0; k<2; k++)
        // {   
        //     for(int j=0; j<n; j++)cout<<g[k][j]<<' ';cout<<endl;
        // }
        
        run();
	}
}
