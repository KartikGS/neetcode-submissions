class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        for(int num: nums) cnt[num]++;

        vector<vector<int>> freq(nums.size()+1);

        for(auto item: cnt) freq[item.second].push_back(item.first);

        vector<int> res;

        for(int i = nums.size(); i>=1; i--){
            for(int j: freq[i]){
                res.push_back(j);
                if(res.size() == k) return res;
            }
        }

        return res;
    }
};
