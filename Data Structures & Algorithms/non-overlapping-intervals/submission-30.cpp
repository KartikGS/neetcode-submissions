class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        		sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
	return a[1]<b[1];
});
int n = intervals.size();
vector<int> dp(n, 1);
for(int i = 1; i<n; i++){
	int idx = bs(intervals, intervals[i][0], i);
	if(idx == 0) dp[i] = dp[i-1];
	else dp[i] = max(dp[i-1], 1+dp[idx-1]);
}
return intervals.size()-dp[n-1];
}
int bs(vector<vector<int>>& intervals, int target, int r){
	int l = 0;
	while(l<r){
		int m = l+(r-l)/2;
		if(intervals[m][1]<=target) l = m+1;
		else r = m;
}
return l;
}
};


