class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>freq;
        vector<int>res;
        for(auto &it : nums)freq[it]++;
        for(auto &it : freq)if(it.second == 1)res.push_back(it.first);
        return res;
    }
};
