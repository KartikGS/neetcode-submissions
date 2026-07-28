class Solution {
public:
    vector<vector<int>> memo;

    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size(), vector<int>(nums.size()+1, -1));
        return dfs(0, -1, nums);
    }
    
    int dfs(int i, int j, vector<int>& nums){
        if(i==nums.size()) return 0;

        if(memo[i][j+1]!=-1) return memo[i][j+1]; 

        int lis = dfs(i+1, j, nums);

        if(j==-1 || nums[i]>nums[j]) lis = max(lis, 1+dfs(i+1, i, nums));

        memo[i][j+1] = lis;

        return lis;
    }
};
