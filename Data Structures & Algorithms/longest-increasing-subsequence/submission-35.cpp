class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for(int i = 0; i<nums.size(); i++){
            int lis = 1;
            for(int j = i-1; j>=0; j--){
                if(nums[i]>nums[j]) lis = max(lis, 1+dp[j]);
            }
            dp[i]= lis;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
