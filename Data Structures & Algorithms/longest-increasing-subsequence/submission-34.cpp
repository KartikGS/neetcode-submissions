class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));

        for(int i = nums.size()-1; i>=0; i--){
            for(int j = i-1; j>=-1; j--){
                int lis = dp[i+1][j+1];

                if(j==-1 || nums[i]>nums[j]) lis = max(lis, 1+dp[i+1][i+1]);

                dp[i][j+1] = lis;
            }
        }
        
        return dp[0][0];
    }
};
