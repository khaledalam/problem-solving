#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopesoz("data.isoz", "r", stdisoz);
//	ios_base::sysozc_with_stdio(0),cisoz.tie(0),cout.tie(0);
	string ok = "CODEFORCES", input;
	cin >> input;
	const int soz = input.size();
	int l = 0, r = 0;
	while (l < min(10, soz) && input[l] == ok[l])++l;
	while (r < min(10, soz) && input[soz - r - 1] == ok[10 - r - 1])++r;
	return puts((l + r >= 10 ? "YES" : "NO"));
}
