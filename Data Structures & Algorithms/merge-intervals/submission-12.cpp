class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxStart = -1;
        for(const vector<int>& interval: intervals){
            maxStart = max(maxStart, interval[0]);
        }

        vector<int> numLine(maxStart+1, -1);
        for(const vector<int>& interval: intervals){
            numLine[interval[0]] = max(numLine[interval[0]], interval[1]);
        }

        int startInterval = -1, have = -1;
        vector<vector<int>> res;

        for(int i = 0; i<=maxStart; i++){
            if(numLine[i]!=-1){
                if(startInterval == -1) startInterval = i;
                have = max(have, numLine[i]);
            }
            if(have == i){
                res.push_back({startInterval, have});
                startInterval = -1;
                have = -1;
            }
        }

        if(startInterval!=-1) res.push_back({startInterval, have});

        return res;
    }
};
