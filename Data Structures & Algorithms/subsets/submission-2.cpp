class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
		vector<int> subset;
		dfs(nums, 0, subset, res);
		return res;
    }

	void dfs(const vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& res){
		if(idx>=nums.size()){
			res.push_back(subset);
			return;
		}
		subset.push_back(nums[idx]);
		dfs(nums, idx+1, subset, res);

		subset.pop_back();
		dfs(nums, idx+1, subset, res);

		return;
	}
};
