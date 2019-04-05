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
	freopen("level1_5.in", "r", stdin); freopen("level1_5.out", "w", stdout);

	int times;
	char c;
	point s, current;
	cin >> s.x >> s.y;
	current = s;
	while (cin >> c >> times) {
		if (c == 'T') {
			times %= 4;
			dir += times;
			dir %= 4;
			continue;
		}
		if (dir == 0) {
			current.x += times;
		} else if (dir == 1) {
			current.y += times;
		} else if (dir == 2) {
			current.x -= times;
		} else {
			current.y -= times;
		}
	}
	cout << current.x << " " << current.y << endl;
}

