class Solution {
public:
	vector<vector<int>> memo;

int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
memo.resize(n, vector<int>(n+1, -1));
return dfs(0, -1, nums);
}

int dfs(int i, int j, const vector<int>& nums){
	if(i>=nums.size()) return 0;
	if(memo[i][j+1]!=-1) return memo[i][j+1];
int res = dfs(i+1, j, nums);
	if(j==-1 || nums[j]<nums[i]) res = max(res, 1+dfs(i+1, i, nums));
	memo[i][j+1] = res;
	return res;
}
};



