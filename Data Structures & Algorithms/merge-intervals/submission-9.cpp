class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxEnd = 0;
        unordered_map<int, int> mp;
        for(vector<int>& interval: intervals){
            mp[interval[0]]++;
            mp[interval[1]]--;
            maxEnd = max(maxEnd, interval[1]);
        }

        int intervalStart = -1;
        int have = 0;
        vector<vector<int>> res;

        for(int i = 0; i<=maxEnd; i++){
            if(mp.find(i) != mp.end()){
                have+=mp[i];
                if(intervalStart == -1) intervalStart = i;
            }
            if(have==0 && intervalStart!=-1){
                res.push_back({intervalStart, i});
                intervalStart = -1;
            }
        }

        return res;
    }
};
