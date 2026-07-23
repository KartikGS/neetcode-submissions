class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }
    bool dfs(vector<int>& nums, int i){
        if(i == nums.size()-1) return true;

        int end = min((int)nums.size()-1, i+nums[i]);

        for(int j = i+1; j<=end; j++) if(dfs(nums, j)) return true;

        return false;
    }
};
