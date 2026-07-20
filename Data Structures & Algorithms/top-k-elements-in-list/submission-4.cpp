class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for(int num: nums) count[num]++;

        int n = nums.size();
        vector<vector<int>> freq(n+1);

        for(auto item: count) freq[item.second].push_back(item.first);

        vector<int> res;
        for(int i = n; i>0; i--){
            for(int num: freq[i]){
                res.push_back(num);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};
