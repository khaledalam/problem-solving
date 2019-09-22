#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5 * 1e6 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

bool states[maxn];

struct FBT {
	int idx;
	FBT* left;
	FBT* right;
	FBT() {
		idx = 1;
		left = right = NULL;
	}
};

void p(FBT * node) {
	if (node == NULL)
		return;
	cout << node->idx << " " << (states[node->idx] ? "Y" : "N") << endl;
	p(node->left);
	p(node->right);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	memset(vis, false, sizeof vis);
//	freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	while (true) {
		int t;
		cin >> t;
		if (t == -1)
			break;
		while (t--) {
			memset(states, false, sizeof states);
			int a, b;
			cin >> a >> b;
			FBT *root = new FBT();
			int res = -1;

			while (b--) {
				FBT *it = root;
				int level = a;
				while (--level) {
					if (states[it->idx]) {
						it->right = new FBT;
						it->right->idx = it->idx * 2 + 1;
						states[it->idx] = !states[it->idx];
						it = it->right;
					} else {
						it->left = new FBT;
						it->left->idx = it->idx * 2;
						states[it->idx] = !states[it->idx];
						it = it->left;
					}
				}
				if (!b)
					res = it->idx;

//				p(root); cout << "-----\n";
			}
			cout << res << endl;
		}
	}
}
