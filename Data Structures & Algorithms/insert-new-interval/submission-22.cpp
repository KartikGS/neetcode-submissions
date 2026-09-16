class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int idx = bs(intervals, newInterval[0]);

        if (idx == n+1) {
            intervals.push_back(newInterval);
            return intervals;
        } else {
            intervals.insert(intervals.begin() + idx, newInterval);
        }

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < n+1; i++) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }

    int bs(const vector<vector<int>>& intervals, int target) {
        int l = 0;
        int r = intervals.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (intervals[m][0] < target)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
