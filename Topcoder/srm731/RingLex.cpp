#include <bits/stdc++.h>
using namespace std;

class RingLex
{

	bool isPrime(int num)
	{
		if (num < 2)
			return 0;
		if (num == 2)
			return 1;
		if (num % 2 == 0)
			return 0;
		int sq = sqrt(num);
		for (int i = 3; i <= sq; i += 2)
		{
			if (num % i == 0)
				return 0;
		}
		return 1;
	}

public:
	string getmin(string s)
	{
		int n = (int) s.size();
		string mi = "~";
		int idx = 0;
		vector<int> primes;
		for (int i = 2; i < n; ++i)
		{
			if (isPrime(i))
				primes.push_back(i);
		}

		for (int i = 0; i < primes.size(); ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				idx = j;
				string tmp;
				while (tmp.size() < n)
				{

					tmp = tmp + s[idx % n];
					idx += primes[i];
				}
				if (mi == "~")
				{
					mi = tmp;
					continue;
				}
				mi = min(mi, tmp);
//				cout << tmp << endl;
			}
		}
		return string(mi);
	}

};
