class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        int prevEnd = intervals[0][1], res = 0;

        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0]>=prevEnd){
                prevEnd = intervals[i][1];
            } else {
                res++;
            }
        }

        return res;
    }
};
