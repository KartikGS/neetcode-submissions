class Solution {
public:
	vector<vector<int>> memo;

    int lengthOfLIS(vector<int>& nums) {
		memo.resize(nums.size()+1, vector<int>(nums.size()+1, -1));
        return dfs(nums, 0, -1);
    }

	int dfs(vector<int>& nums, int i, int j){
		if(i==nums.size()) return 0;
		if(memo[i+1][j+1]!=-1) return memo[i+1][j+1];
		int res = dfs(nums, i+1, j);
		if(j==-1 || nums[i]>nums[j]) res = max(res, 1+dfs(nums, i+1, i));
		memo[i+1][j+1] = res;
		return res;
	}
};
