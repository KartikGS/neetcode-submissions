class Solution {
public:
	vector<unordered_map<bool, int>> memo;
    int maxSubArray(vector<int>& nums) {
		memo.resize(nums.size());
		return dfs(nums, 0, false);
    }

	int dfs(vector<int>& nums, int i, bool flag){
		if(i==nums.size()-1) return flag?max(0, nums[i]):nums[i];
		if(memo[i].count(flag)) return memo[i][flag];

		if(flag){
			memo[i][flag] = max(0, nums[i]+dfs(nums, i+1, flag));
		} else {
			memo[i][flag] = max(dfs(nums, i+1, flag), nums[i]+dfs(nums, i+1, true));
		}
		return memo[i][flag];
	}
};
