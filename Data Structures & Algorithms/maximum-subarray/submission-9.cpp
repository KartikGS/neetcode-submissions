class Solution {
public:
    vector<unordered_map<bool, int>> memo;
    int maxSubArray(vector<int>& nums) {
        memo.resize(nums.size());
        return dfs(0, false, nums);
    }

    int dfs(int i, bool flag, vector<int>& nums){
        if(i==nums.size()-1) return flag?max(0, nums[i]):nums[i];
        
        if(memo[i].find(flag) != memo[i].end()) return memo[i][flag];

        if(flag){
            memo[i][flag] = max(nums[i]+dfs(i+1, true, nums), 0);
        } else {
            memo[i][flag] = max(nums[i]+dfs(i+1, true, nums), dfs(i+1, false, nums));
        }

        return memo[i][flag];
    }
};
