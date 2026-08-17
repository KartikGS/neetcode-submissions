class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for(int num:nums){
            int len = res.size();
            for(int i = 0; i<len; i++){
                vector<int> tmp = res[i];
                tmp.push_back(num);
                res.push_back(tmp);
            }
        }

        return res;
    }
};
