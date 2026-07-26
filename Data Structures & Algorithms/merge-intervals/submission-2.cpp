class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++){
            int start = intervals[i][0], end = intervals[i][1];
            int lastEnd = res.back()[1];

            if(lastEnd>=start){
                res.back()[1] = max(lastEnd, end);
            } else{
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
