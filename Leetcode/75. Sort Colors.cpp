class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(const int &i: nums){
            a+=i==0;
            b+=i==1;
            c+=i==2;
        }
        int idx = 0;
        while (a--)nums[idx++] = 0;
        while (b--)nums[idx++] = 1;
        while (c--)nums[idx++] = 2;
    }
};
