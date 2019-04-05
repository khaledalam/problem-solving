//Ninjo
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

/*
struct data {
	int first;
	int second;
	int size;
};
*/

vector<pair<int, int>> res[100];
vector<int> A, B;
map<int, bool> sv;
map<char, bool> rp;
string a = "xxxxx";
int cnt = 0;

void printNumbersWithPro(int s) {
	if (s > 4) {
		cout << a << endl;
		cnt++; return;
	}

	for (char j = '0'; j <= '9'; ++j) {
		if (!rp[j]) {
			rp[j] = true;
			a[s] = j;
			printNumbersWithPro(s + 1);
			rp[j] = false;
		}
	}
}

void init(int s) {

	if (s == 5) {
		stringstream ss;
		int buf;
		ss << a;
		ss >> buf;
		A.emplace_back(buf);
		return;
	}

	for (char j = '0'; j <= '9'; ++j) {
		if (!rp[j]) {
			rp[j] = true;
			a[s] = j;
			init(s + 1);
			rp[j] = false;
		}
	}
}

short soz(int v) {
	int r = 0;
	while (v) {
		r++; v /= 10;
	}
	return r;
}
bool two(int x, int y) {
	map<int, int> m;
	if (soz(x) != 5)m[0]++;
	if (soz(y) != 5)m[0]++;
	if (m[0] > 1)return false;
	while (x) {
		m[x % 10]++;
		if (m[x % 10] > 1)return false;
		x /= 10;
	}

	while (y) {
		m[y % 10]++;
		if (m[y % 10] > 1)return false;
		y /= 10;
	}
	return true;

}
void test(int x) {
	if (res[x].size())
		return;
	const int mx = A.size();
	for (int j = 0; j < mx; j++) {
		if (binary_search(A.begin(), A.end(), (x * A[j]))&& two((x * A[j]), A[j])) {
			res[x].push_back(make_pair((x * A[j]), A[j]));
			sv[x] = true;
		} else if (A[j] * x > A.back())
			break;
	}
}

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//test:
//	printNumbersWithPro(0);
//	cout << ">>\n"<<cnt << endl;
//	return 0;  //30240

	init(0);
	B = A;
	for (int i = 2; i <= 79; ++i) test(i);

	int n;
	bool f = false;
	while (cin >> n) {

		if (!n) break;
		else if (f)cout << "\n"; f = true;

		if (!sv[n]) {
			cout << "There are no solutions for " << n << ".\n";
			continue;
		}

		for (auto it : res[n])
		cout << setw(5) << setfill('0') << it.first << " / " << setw(5) << setfill('0') << it.second << " = " << n << "\n";
	}
	return 0;
}
