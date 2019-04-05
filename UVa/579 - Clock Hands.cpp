// Ninjo ~ khaledalam.net@gmail.com
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define sz(A)      (int)(A).size()
#define all(B)     (B).begin(),(B).end()
#define file       freopen("input.txt", "r", stdin)
#define ios        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// 579 - Clock Hands

void display(double h, double m) {
	if (h == 12)h = 0;
	double hour_angle = 0.5 * (h * 60 + m);
	double minute_angle = 6 * m;
	double angle = (float) abs(hour_angle - minute_angle);
	angle = min(360 - angle, angle);
	cout<<fixed<<setprecision(3)<<angle<<endl;
}

int main() {
// file;
	string s;
	while (getline(cin, s) && s != "0:00") {
		double h, m;
		stringstream ss;
		replace(all(s), ':', ' ');
		ss << s;
		ss >> h;
		ss >> m;
		display(h, m);
	}

	return 0;
}
