//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;
//https://www.codechef.com/SNCKPB17/problems/SNELECT
int main() {
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int a=0,b=0;
	    for (char c : s) {
	        if(c == 's')a++;
	        else b++;
	    }
	    
	    for(int i=0; i<(int)s.size()-1; i++)
	    {
	        if( (s[i] == 'm' && s[i+1] == 's' ) || s[i] == 's' && s[i+1] == 'm' )a--,i++;
	    }
	    cout<< (a == b ? "tie\n" : ( a>b  ? "snakes\n" : "mongooses\n" ));
	}
}
