#include <bits/stdc++.h>
using namespace std;
int len;
string in;

int main() {
//	freopen("data.in", "r", stdin);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> len >> in;
	list<char> res;
	auto ptr = in.begin();
	if (len == 1)return puts(in.c_str()), 0;
	bool dir = (len & 1);
	while (len > 0) {
//		short mid = len / 2 + (len & 1 ? 0 : -1);
		if (!dir) {
			if(ptr!=in.end())res.push_front(*ptr++);
			if(ptr!=in.end())res.push_back(*ptr++);
		} else {
			if(ptr!=in.end())res.push_back(*ptr++);
			if(ptr!=in.end())res.push_front(*ptr++);
		}
		len -= 2;
	}
	for (char c : res)cout << c;
}
