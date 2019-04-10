#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e5 + 10;
const int inf = (1953125 << 9);
bool vis[maxn];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis, false, sizeof vis);
	// freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	string a, b;
	cin >> a >> b;
	map<char, int> freq;
	for (char &c : b)
		freq[c]++;

	int same = 0, difCase = 0;

	for(int i = 0; i < a.size(); i++)
	{
		if (freq[a[i]] > 0)
		{
			vis[i] = true;
			same++;
			freq[a[i]]--;
		}
	}

	for(int i = 0; i < a.size(); i++)
	{
		char orr = (tolower(a[i]) == a[i] ? toupper(a[i]) : tolower(a[i]));
		if(freq[orr] > 0 && !vis[i]){
			freq[orr]--;
			difCase++;
		}
	}

	cout << same << " " << difCase << endl;
}
