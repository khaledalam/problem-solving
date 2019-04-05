#include <bits/stdc++.h>
 
using namespace std;
 
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)
 
const double PI = acos(-1);
 
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
 
 
	string s;
	int t, l;
	cin >> t;
	while (t--) {
		cin >> l;
		cin >> s;
		char nw = 'H';
		for (int i = 0; i < l; ++i) {
			if (s[i] == '.') {
				continue;
			}
			if (nw != s[i]) {
				nw = '.';
				break;
			}
			if (nw == s[i]) {
				if (s[i] == 'T') {
					nw = 'H';
				} else {
					nw = 'T';
				}
			}
		}
		if(nw=='.' || nw =='T'){
			cout<<"Invalid"<<endl;
		}else{
			cout<<"Valid"<<endl;
		}
	}
 
	return 0;
 
}
