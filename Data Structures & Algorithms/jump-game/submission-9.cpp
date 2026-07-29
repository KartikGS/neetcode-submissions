class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
		
		vector<bool> dp(n, false);

		dp[n-1] = true;

		for(int i = n-2; i>=0; i--){
			for(int j = i+1; j<=min(n-1, i+nums[i]); j++){
				dp[i] = dp[j];
				if(dp[i]) break;
			}
		}

		return dp[0];
    }
};
