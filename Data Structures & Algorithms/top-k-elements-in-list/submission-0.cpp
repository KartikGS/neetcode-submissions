class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num: nums) mp[num]++;

        vector<pair<int, int>> numToFreq;

        for(auto i: mp) numToFreq.push_back(i);

        sort(numToFreq.begin(), numToFreq.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second>b.second;
        });

        vector<int> res;
        for(int i = 0;i<k;i++) res.push_back(numToFreq[i].first);
        return res;
    }
};
