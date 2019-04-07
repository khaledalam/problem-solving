#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 4 * 1e5 + 8;
bool vis[maxn];
const int inf = (1953125 << 9);

// class num{
// 	string value;
// 	num(string par){
// 		this->value = par;
// 	}

// 	bool contains4(){
// 		for(char &ch: this->value)if(ch == '4')return true;
// 		return false;
// 	}

// 	void operator--(){
// 		reverse(this->value.begin(), this.value.end());
// 		for (char &ch : this->value)
// 		if (ch == '0')
// 			ch = '9';
// 		else
// 		{
// 			ch--;
// 			break;
// 		}
// 		reverse(this->value.begin(), this.value.end());
// 	}
// }

bool check(long long x)
{
	while(x){
		int d = x%10;
		if(d==4)return false;
		x/=10;
	}
	return true;
}

int main()
{
	srand(time(NULL));
  
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// memset(vis, false, sizeof vis);
	// freopen("data.in", "r", stdin); // freopen("data.out", "w", stdout);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		long long n;
		cin >> n;


		long long min = 1;
		long long max = n-1;
		
		
		while(true){
			long long f = (min + (rand() % (long long)(max - min + 1)));
			long long s = n - f;

			if(check(f) && check(s)){
				cout << "Case #" << tt << ": " << f << " " << s << endl;
				break;
			}
		}
	}
	return 0;
}

