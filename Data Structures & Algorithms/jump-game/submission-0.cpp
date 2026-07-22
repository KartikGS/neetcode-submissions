class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }

    bool dfs(vector<int>& nums, int i){
        if(i==nums.size()-1) return true;
        if(i>=nums.size()) return false;

        for(int j = 1; j<=nums[i]; j++){
            if(dfs(nums, i+j)) return true;
        }

        return false;
    }
};
