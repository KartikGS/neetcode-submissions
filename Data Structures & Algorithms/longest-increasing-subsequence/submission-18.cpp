class Solution {
public:

    vector<vector<int>> memo;

    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size(), vector<int>(nums.size()+1, -1));
        return dfs(nums, 0, -1);
    }

    int dfs(vector<int>& nums, int i, int j){
        if(i == nums.size()) return 0;
        if(memo[i][j+1]!=-1) return memo[i][j+1];

        int lis = dfs(nums, i+1, j);

        if(j==-1 || nums[j]<nums[i]) lis = max(lis, 1+dfs(nums, i+1, i));

        memo[i][j+1] = lis;
        return lis;
    }
};
