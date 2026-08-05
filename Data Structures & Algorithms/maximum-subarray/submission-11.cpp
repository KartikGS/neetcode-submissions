class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1] = nums[n-1];

        for(int i = n-2; i>=0; i--){
            dp[i] = max(nums[i], nums[i]+dp[i+1]);    
        }//7, 5, 8, 4, 6,4,3,4

        return *max_element(dp.begin(), dp.end());
    }
};
