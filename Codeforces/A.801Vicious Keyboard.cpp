//KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

char s[101];
int mx = 0, len;

int brute(int x)
{
	int ret = 0;
	char tmp[len];
	strncpy(tmp, s, len);
	if (x != -1)tmp[x] = tmp[x] == 'V' ? 'K' : 'V';
	for (int i = 1; i < len; ++i)
	if (tmp[i - 1] == 'V' && tmp[i] == 'K')ret++, i++;
	return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	scanf("%s", s);
	len = (int) strlen(s);
	mx = max(mx, brute(-1));
	for (int i = 0; i < len; ++i)
	{
		mx = max(mx, brute(i));
	}
	return cout << mx, 0;
}
