class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervals = [[1,2],[3,5],[9,10]], newInterval = [6,7]
        int n = intervals.size();//3

        int start = n-1;//2

        while(start>=0 && intervals[start][0]>newInterval[0]) start--;//1

        int end = 0;

        while(end<n && intervals[end][1]<newInterval[1]) end++;//2

        vector<vector<int>> res;

        for(int i = 0;i<start;i++) res.push_back(intervals[i]);

        if(start!=-1){
            if(newInterval[0] <= intervals[start][1]){
                newInterval[0] = intervals[start][0];//[1,5]
            } else{
                res.push_back(intervals[start]);
            }
        }
        if(end!=n){
            if(newInterval[1]>=intervals[end][0]){
                newInterval[1] = intervals[end][1];//1,6
                end++;//2
            }
        }

        res.push_back(newInterval);

        for(int i = end;i<n;i++) res.push_back(intervals[i]);

        return res;
    }
};
