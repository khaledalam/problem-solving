class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int mi = 1e9;
        const int len = (int)chips.size();
        
        for(int i=0; i<len; i++){
            int cnt = 0;
            for(int j=0; j<len; j++){
                if(i==j)continue;
                cnt += (abs(chips[i] - chips[j]) & 1 ? 1 : 0);
            }
            // cout<<cnt<<endl;
            mi = min(mi, cnt);
        }
        return mi;
    }
};
