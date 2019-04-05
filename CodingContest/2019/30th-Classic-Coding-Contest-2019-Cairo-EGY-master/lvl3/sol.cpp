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
	freopen("level3_5.in", "r", stdin);
	freopen("level3_5.out", "w", stdout);

	int times;
	char c;
	point s, current, sz;
	cin >> sz.x >> sz.y >> s.x >> s.y;
	current = s;
	map<int, pair<int, int>> path;

	stringstream ss;
	string str;
	getchar();
	getline(cin, str);
	ss << str;
	int tickCnt = 1;
	path[0] = {s.x,s.y};
	while (ss >> c && ss >> times) {
		if (c == 'T') {
			times %= 4;
			dir += times;
			dir %= 4;
			continue;
		}

		if (dir == 0) {
			while (times--) {
				current.x++;
				path[tickCnt++] = {current.x, current.y};
			}
		} else if (dir == 1) {
			while (times--) {
				current.y++;
				path[tickCnt++] = {current.x, current.y};
			}
		} else if (dir == 2) {
			while (times--) {
				current.x--;
				path[tickCnt++] = {current.x, current.y};
			}
		} else {
			while (times--) {
				current.y--;
				path[tickCnt++] = {current.x, current.y};
			}
		}
	}
	double speed;
	int aliens;
	cin >> speed >> aliens;
	vector<int> startFrom;
	for (int i = 0; i < aliens; ++i) {
		int x;
		cin >> x;
		startFrom.push_back(x);
	}
	int q;
	cin >> q;
	point pv = current;
	for (int i = 0; i < q; ++i) {
		int tick, id;
		cin >> tick >> id;
		cout << tick << " " << id << " ";

		int ownSteps = ( tick - startFrom[id] ) * speed;
//		cout << ownSteps << endl;
		if (!path[ownSteps].first && !path[ownSteps].second) {
			cout << pv.x << " " << pv.y << endl;
			continue;
		}
		cout << path[ownSteps].first << " " << path[ownSteps].second << endl;

	}
}

