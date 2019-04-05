#include <bits/stdc++.h>
using namespace std;

string in;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> in;
	int idx = 0, mx = 0, cnt = 0;
	pair<int, int> inter;
	bool f = true;
	for (int i = 0; i < in.size(); ++i) {
		if (in[i] != 'a') {
			cnt++;
			f = false;
			inter = {idx,i};
		} else {
			if(cnt)break;
			idx = i+1;
		}
	}
	if(f)inter={in.size()-1,in.size()};
	for (int i = inter.first; i <= inter.second; ++i){in[i]--; in[i]=(in[i]=='`'?'z':in[i]);}

//	cout <<inter.first << " "<< inter.second <<" ' "<<*ptr<<"\n";
//	while(ptr++ != in.begin()+inter.second);

	cout<<in;
}
