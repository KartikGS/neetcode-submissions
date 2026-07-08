class Solution {
public:
    vector<vector<int>> dp;

    int lengthOfLIS(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        dp.resize(nums.size(), vector<int>(2002));
        return dfs(nums, 0, -1001);
    }

    //return lenght of subsequence
    int dfs(vector<int>& nums, int i, int maxNum){
        if(i>=nums.size()) return 0;
        
        if(dp[i][maxNum+1001]!=0) return dp[i][maxNum+1001];

        if(nums[i]<=maxNum){ 
            dp[i][maxNum+1001] = dfs(nums, i+1, maxNum);
            return dp[i][maxNum+1001];
        }
        dp[i][maxNum+1001] = max(dfs(nums, i+1, maxNum), 1+dfs(nums, i+1, nums[i]));
        return dp[i][maxNum+1001];
    }
};
