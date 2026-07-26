class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxStart = 0;
        for(const auto& interval: intervals){
            maxStart = max(maxStart, interval[0]);
        }

        vector<int> mp(maxStart+1, 0);
        for(const auto& interval: intervals){
            mp[interval[0]] = max(interval[1]+1, mp[interval[0]]);
        }

        vector<vector<int>> res;
        int intervalStart = -1;
        int have = -1;

        for(int i = 0; i<mp.size(); i++){
            if(mp[i] != 0){
                if(intervalStart == -1) intervalStart = i;
                have = max(mp[i]-1, have);
            }
            if(i == have){
                res.push_back({intervalStart, have});
                have = -1;
                intervalStart = -1;
            }
        }
        if(intervalStart!=-1){
            res.push_back({intervalStart, have});
        }

        return res;
    }
};
