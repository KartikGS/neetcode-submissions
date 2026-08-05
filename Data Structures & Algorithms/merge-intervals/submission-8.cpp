class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        
        for(int i = 0; i<intervals.size(); i++){
            if(i==0 || res.back()[1]<intervals[i][0]) res.push_back(intervals[i]);
            else res.back()[1] = max(res.back()[1], intervals[i][1]);
        }

        return res;
    }
};
