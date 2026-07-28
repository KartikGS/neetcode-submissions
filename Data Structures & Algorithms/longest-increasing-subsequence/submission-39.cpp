class Solution {
public:
    vector<int> memo;

    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        int lis = 1;
        for(int i = 0; i<nums.size(); i++){
            lis = max(lis,dfs(i, nums));
        }
        return lis;
    }
    
    int dfs(int i, vector<int>& nums){
        if(memo[i]!=-1) return memo[i]; 

        int lis = 1;
        for(int j = i+1; j<nums.size(); j++){
            if(nums[i]<nums[j]) lis = max(lis, 1+dfs(j, nums));
        }

        memo[i] = lis;

        return memo[i];
    }
};
