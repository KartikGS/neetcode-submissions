class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int res = 0, lastEnd = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < lastEnd) {
                res++;
				lastEnd = min(intervals[i][1], lastEnd);
            } else {
                lastEnd = intervals[i][1];
            }
        }
        return res;
    }
};
