class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for(int i = 0; i<nums.size(); i++){
            int len = res.size();
            for(int j = 0; j<len; j++){
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }
        
        return res;
    }
};
