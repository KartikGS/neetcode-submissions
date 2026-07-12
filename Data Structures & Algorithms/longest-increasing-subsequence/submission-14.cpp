class Solution {
public:

    vector<int> memo;

    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size(), -1);

        int LIS = 1;

        for(int i = 0; i<nums.size(); i++){
            LIS = max(LIS, dfs(nums, i));
        }

        return LIS;
    }

    int dfs(vector<int>& nums, int i){
        if(memo[i]!=-1) return memo[i];

        int LIS = 1;
        for(int j = i+1; j<nums.size(); j++){
            if(nums[j]>nums[i]) LIS = max(LIS, 1+dfs(nums, j));
        }

        memo[i] = LIS;
        return LIS;
    }
};
