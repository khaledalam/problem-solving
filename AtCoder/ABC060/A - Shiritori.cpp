//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b, c;
	cin >> a >> b >> c;
	puts(a.back() == b.front() && b.back() == c.front() ? "YES" : "NO");
}
