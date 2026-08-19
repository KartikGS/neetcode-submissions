class Solution {
public:
	vector<int> memo;
    bool canJump(vector<int>& nums) {
		memo.resize(nums.size(), -1);
        return dfs(nums, 0);
    }
	
	bool dfs(vector<int>& nums, int i){
		if(i+nums[i]>=nums.size()-1) return true;
		if(memo[i]!=-1) return memo[i] == 1;
		for(int j = i+1; j<=i+nums[i]; j++){
			if(dfs(nums, j)) {
				memo[i] = 1;
				return true;
			}
		}
		memo[i] = 0;
		return false;
	}
};
