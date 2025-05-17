class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Khaled Alam <khaledalam.net@gmail.com>
        
        unordered_map<int,int>ump;
        int idx = 0;
        for(const int &val: nums) {
            int dif = target - val;
            if (ump.count(target - val)) {
                return vector<int>{ump[target - val], idx};
            }
            ump[val] = idx++;
        }
        return {};
    }
};
