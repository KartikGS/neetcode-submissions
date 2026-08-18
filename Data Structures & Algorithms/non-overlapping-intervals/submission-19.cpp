class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int lastEnd = intervals[0][1];
        int res = 1;
        for(int i = 1; i<n; i++){
            if(intervals[i][0]>=lastEnd){
                res++;
                lastEnd = intervals[i][1];
            } else {
                lastEnd = min(lastEnd, intervals[i][1]);
            }
        }
        return intervals.size()-res;
    }
};
