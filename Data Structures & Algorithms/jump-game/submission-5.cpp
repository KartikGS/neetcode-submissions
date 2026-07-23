class Solution {
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> memo;
        return dfs(nums, 0, memo);
    }
    bool dfs(vector<int>& nums, int i, unordered_map<int, bool>& memo){
        if(memo.count(i)) return memo[i];
        if(i == nums.size()-1) return true;
        if(nums[i]==0) return false;

        int end = min((int)nums.size()-1, i+nums[i]);

        for(int j = i+1; j<=end; j++) {
            if(dfs(nums, j, memo)) {
                memo[i] = true;
                return true;
            }
        }

        return false;
    }
};
