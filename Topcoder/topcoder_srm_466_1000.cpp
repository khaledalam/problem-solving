// Ninjo ~ khaledalam.net@gmail.com
#include <bits/stdc++.h>
using namespace std;
#define sz(A)      (int)(A).size()
#define all(B)     (B).begin(),(B).end()
#define ios        ios_base::sync_with_stdio(0);
#define file       freopen("input.txt", "r", stdin)

//topcoder srm 466 1000

class MatrixGame {

public:
	vector<string> getMinimal(vector<string> mat) {

		vector<string>good = mat;
		vector<int> per;
		for (int i = 0; i < sz(mat[0]); ++i) {
			per.push_back(i);
		}
		do{
			vector<string>tmp(sz(mat),mat[0]);
			for (int i = 0; i < sz(mat); ++i) {
				for (int j = 0; j < sz(mat[i]); ++j) {
					tmp[i][per[j]]=mat[i][j];
				}
			}
			sort(all(tmp));
			if(tmp<good)good = tmp;
		}while(next_permutation(all(per)));

		return good;

	}
};
