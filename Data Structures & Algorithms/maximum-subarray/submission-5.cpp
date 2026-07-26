class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[n-1] = nums[n-1];

        for(int i = n-2; i>=0; i--){
            dp[i] = max(nums[i]+dp[i+1], nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
