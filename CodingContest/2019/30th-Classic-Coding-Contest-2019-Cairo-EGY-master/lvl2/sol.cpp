#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e5 + 8;
bool vis[maxn];
const int inf = ( 1953125 << 9 );

struct point {
	int x, y;
};
int dir = 0;

int main() {
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	memset(vis, false, sizeof vis);
	freopen("level2_5.in", "r", stdin);
	freopen("level2_5.out", "w", stdout);

	int times;
	char c;
	point s, current, sz;
	cin >> sz.x >> s.y >> s.x >> s.y;
	cout << s.x << " " << s.y << endl;
	current = s;
	while (cin >> c >> times) {
		if (c == 'T') {
			times %= 4;
			dir += times;
			dir %= 4;
			continue;
		}
		if (dir == 0) {
			while (times--) {
				current.x++;
				cout << current.x << " " << current.y << endl;
			}
		} else if (dir == 1) {
			while (times--) {
				current.y++;
				cout << current.x << " " << current.y << endl;
			}
		} else if (dir == 2) {
			while (times--) {
				current.x--;
				cout << current.x << " " << current.y << endl;
			}
		} else {
			while (times--) {
				current.y--;
				cout << current.x << " " << current.y << endl;
			}
		}
	}
}

