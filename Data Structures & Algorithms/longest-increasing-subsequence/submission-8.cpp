class Solution {
public:
    vector<vector<int>> memo;

    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size(), vector<int>(nums.size(), -1));
        return dfs(nums, 0, -1);
    }

    int dfs(vector<int>& nums, int i, int mei){ //mei - max element index
        if(i>=nums.size()) return 0;
        if(mei != -1 && memo[i][mei] != -1) return memo[i][mei];

        int lis = dfs(nums, i+1, mei); // lis - longest increasing subsequence

        if(mei == -1 || nums[i]>nums[mei]) lis = max(lis, 1 + dfs(nums, i+1, i));

        if(mei != -1) memo[i][mei] = lis;
        return lis;
    }
};
