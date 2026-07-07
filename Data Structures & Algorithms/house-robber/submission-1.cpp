class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i){
        if(i>=nums.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        dp[i] = max(nums[i]+dfs(nums, i+2), dfs(nums, i+1));
        
        return dp[i];
    }
};
