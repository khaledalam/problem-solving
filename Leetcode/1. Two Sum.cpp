class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Khaled Alam <khaledalam.net@gmail.com>

        vector<pair<int,int>> pr;
        int idx = 0;
        for(const int &it: nums) {
            pr.push_back({it, idx++});
        }
        
        unordered_map<int,int>ump;
        for(const auto &[val, idx]: pr) {
            int dif = target - val;
            if (ump.count(dif)) {
                return vector<int>{ump[dif], idx};
            }
            ump[val] = idx;
        }
        return {};
    }
};
