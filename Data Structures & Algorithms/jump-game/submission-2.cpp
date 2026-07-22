class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n-1] = true;

        for(int i = n-2; i>=0; i--){
            int j=1;
            while(j<=nums[i] && i+j<n){
                if(dp[i+j]){
                    dp[i] = true;
                    break;
                }
                j++;
            }
        }

        return dp[0];
    }
};
