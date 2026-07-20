class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // start empty set
        // sets of all sizes from 0 to nums.size()
        // empty set 
        // add all numbers to empty set
        // 1,2,3
        // 1 2, 1 3
        
        vector<vector<int>> res;
        res.push_back({});
        for(int i = 0;i<nums.size();i++){
            int len = res.size();
            for(int j=0;j<len;j++){
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
