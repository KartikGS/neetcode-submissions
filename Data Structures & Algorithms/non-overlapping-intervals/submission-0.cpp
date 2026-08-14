class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //[[1,2],[2,4],[1,4]]
        //1,2   1,4     2,4
        //1,2   1, 
        //1,5    2,3     4,5
        // 0 0 <- 0
        //1+<-0 <-0 or 2
        int n = intervals.size();//3
        vector<int> dp(n, 0);// 1 1 0

        sort(intervals.begin(), intervals.end());

        for(int i = n-2; i>=0; i--){
            if(intervals[i][1]>intervals[i+1][0]){
                dp[i] = 1+dp[i+1];
                int j = i+1;
                while(j<n && intervals[i][1]>intervals[j][0]) j++;
                if(j==n) dp[i] = min(dp[i], j-i-1);
                else dp[i] = min(dp[i], j-i-1+dp[j]);
            } else {
                dp[i] = dp[i+1];
            }
        }

        return dp[0];
    }
};
