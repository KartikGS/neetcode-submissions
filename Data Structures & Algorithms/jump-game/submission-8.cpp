class Solution {
public:
	unordered_map<int, bool> memo;

    bool canJump(vector<int>& nums) {
        memo.clear();
		return dfs(nums, 0);
    }

	bool dfs(vector<int>& nums, int i){
		if(i == nums.size()-1) return true;

		if(memo.count(i)) return memo[i];

		for(int j = i+1; j<= min((int)nums.size()-1, i+nums[i]) ; j++){
			if(dfs(nums, j)) return true;
		}

		memo[i] = false;

		return false;
	}
};
