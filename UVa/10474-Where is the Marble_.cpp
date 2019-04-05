#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, tmp, tCase = 0;
	while (cin >> n >> m && n && m && ++tCase) {
		set<int> b;
		map<int, int> freq;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			b.insert(tmp);
			freq[tmp]++;
		}
		map<int, int> memo;
		long long times = 1,prev = *b.begin();
		memo[prev]=1;
		for (int it : b) {
			if(prev != it){
				prev = it;
				memo[it] = times;
			}
			times += freq[it];
		}
//		for(auto h : memo)cout<<h.first<<": "<<h.second<<' ';
		cout << "CASE# " << tCase << ":\n";
		for (int i = 0; i < m; ++i) {
			cin >> tmp;
			auto findIt = binary_search(b.begin(), b.end(), tmp);
			if (!findIt) {
				cout << tmp << " not found" << '\n';
			} else {
				cout << tmp << " found at " << memo[tmp] << '\n';
			}
		}
	}
}


//Time Limit sol.

//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
////	freopen("data.in", "r", stdin);
////	freopen("data.out", "w", stdout);
////	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int n, m, tmp, tCase = 0;
//	while (cin >> n >> m && n && m && ++tCase) {
//		set<int> b;
//		map<int, int> freq;
//		for (int i = 0; i < n; ++i) {
//			cin >> tmp;
//			b.insert(tmp);
//			freq[tmp]++;
//		}
//		cout << "CASE# " << tCase << ":\n";
//		for (int i = 0; i < m; ++i) {
//			cin >> tmp;
//			auto findIt = binary_search(b.begin(), b.end(), tmp);
//			if (!findIt) {
//				cout << tmp << " not found" << '\n';
//			} else {
//				long long tmpCol = 1;
//				for (int it : b) {
//					if(it==tmp)break;
//					tmpCol += freq[it];
//				}
//				cout << tmp << " found at " << tmpCol << '\n';
//			}
//		}
//	}
//}
