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
        int nos = pow(2, nums.size());
        for(int i = 0;i<nos;i++){
            vector<int> temp = {};
            for(int j=0;j<nums.size();j++){
                if(1<<j & i) temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
