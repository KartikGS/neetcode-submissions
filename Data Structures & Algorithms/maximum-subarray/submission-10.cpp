class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[n-1][0] = dp[n-1][1] = nums[n-1];

        for(int i = n-2; i>=0; i--){
            dp[i][1] = max(nums[i], nums[i]+dp[i+1][1]);
            dp[i][0] = max(dp[i+1][0], dp[i][1]);
        }//8,7 8,5 8,8 6,4 6,6 4,4 4,3 4,3

        return dp[0][0];
    }
};
