//@author KhaledAlam.net
#include <bits/stdc++.h>
using namespace std;

class RangeEncoding
{

public:
	int minRanges(vector<int> arr)
	{
		int res = 1;
		for (unsigned int i = 1; i < arr.size(); ++i)
		{
			if (arr[i] - arr[i - 1] > 1)res++;
		}
		return res;
	}

};
