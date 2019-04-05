#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n;
pair<int, int> a[N];
int changes = 0;

void go(int s) {

	for (int i = s; i < n; i++) {
		bool f = false;
		if (a[i - 1].second != a[i].first) {
			if (a[i - 1].first == a[i].first && i == 1) {
				changes++;
				swap(a[i - 1].first, a[i - 1].second);
				go(i);
				swap(a[i - 1].first, a[i - 1].second);
				f = true;
			}

			if (a[i - 1].second == a[i].second) {
				changes++;
				swap(a[i].first, a[i].second);
				go(i);
				swap(a[i].first, a[i].second);
				f = true;
			}
			if (a[i - 1].first == a[i].second && i == 1) {
				changes+=2;
				swap(a[i].first, a[i].second);
				swap(a[i - 1].first, a[i - 1].second);
				go(i);
				swap(a[i].first, a[i].second);
				swap(a[i - 1].first, a[i - 1].second);
				f = true;
			}

			if(!f && a[i - 1].second != a[i].first){
					cout<<-1;
				exit(0);
			}else if(!f){
			changes--;
				return;
			}

		}

	}
	cout<<changes;
	exit(0);

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	go(1);

}
