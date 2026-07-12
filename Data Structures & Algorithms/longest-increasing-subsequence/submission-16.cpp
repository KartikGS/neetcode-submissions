class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 2 4 5 7 - 4,7
        vector<int> v;
        v.push_back(nums[0]);

        for(int i = 1;i<nums.size(); i++){
            if(nums[i]>v.back()) v.push_back(nums[i]);
            else{
                int gte = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[gte] = nums[i];
            }
        }
        return v.size(); 
    }
};
