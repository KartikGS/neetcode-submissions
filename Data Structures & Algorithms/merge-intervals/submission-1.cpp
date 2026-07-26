class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++){
            vector<int> tmp = res.back();
            int start = tmp[0], end = tmp[1];
            if(intervals[i][0]<=end){
                res.pop_back();
                res.push_back({min(intervals[i][0], start), max(intervals[i][1], end)});
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
