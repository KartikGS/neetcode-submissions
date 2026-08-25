class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int idx = bs(intervals, newInterval[0]);

        intervals.insert(intervals.begin()+idx, newInterval);

        for(int i = 0; i<intervals.size(); i++){
            if(res.empty() || res.back()[1]<intervals[i][0]) res.push_back(intervals[i]);
            else res.back()[1] = max(res.back()[1], intervals[i][1]);
        }

        return res;
    }

    int bs(vector<vector<int>>& intervals, int target){
        int l = 0;
        int r = intervals.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(intervals[m][0]<target) l = m+1;
            else r=m-1;
        }
        return l;
    }
};
