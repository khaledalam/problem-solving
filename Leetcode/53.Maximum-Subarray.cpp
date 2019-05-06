class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long ret = -8e9;
        long long cnt = 0;
        for(auto &it : nums){
            if(cnt >= 0){
                cnt += it;
            }else {
                cnt = it;
            }
            ret = max(ret, cnt);
        }
        
        return ret;
        
    }
};
