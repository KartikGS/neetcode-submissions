class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, res, 0, {});
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>&res, int i, vector<int> tmp){
        if(i==nums.size()){ 
            res.push_back(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        dfs(nums, res, i+1, tmp);

        tmp.pop_back();
        dfs(nums, res, i+1, tmp);
    }
};
