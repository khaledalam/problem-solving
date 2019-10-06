class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int,int>freq;
        for(auto &it: arr1)freq[it]++;
        for(auto &it: arr2)freq[it]++;
        for(auto &it: arr3)freq[it]++;
        vector<int>ret;
        for(auto &it: freq)if(it.second == 3)ret.push_back(it.first);
        return ret;
    }
};
