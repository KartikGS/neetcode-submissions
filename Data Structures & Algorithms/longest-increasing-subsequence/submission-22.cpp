class Solution {
public:

    vector<int> memo;

    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        int lis = 1;
        for(int i = 0; i<nums.size(); i++){
            lis = max(lis, dfs(nums, i));
        }
        return lis;
    }

    int dfs(vector<int>& nums, int i){
        if(memo[i]!=-1) return memo[i];

        int lis = 1;
        for(int j = i-1; j>=0; j--){
            if(nums[j]<nums[i]) lis = max(lis, 1+dfs(nums, j));
        }
        
        memo[i] = lis;
        return lis;
    }
};
//