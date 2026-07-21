class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        dp.push_back(nums[0]);
        int lis = 1;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>dp.back()){
                lis++;
                dp.push_back(nums[i]);
                continue;
            }
            int idx = lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();

            dp[idx] = nums[i];
        }
        
        return lis;
    }
};
