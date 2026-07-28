class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int target = newInterval[0];
        int l = 0, r = intervals.size()-1;

        while(l<=r){
            int m = l+(r-l)/2;
            if(intervals[m][0]<target){
                l = m+1;
            } else {
                r = m-1;
            }
        }

        intervals.insert(intervals.begin()+l, newInterval);

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++){
            if(res.back()[1]>=intervals[i][0]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
