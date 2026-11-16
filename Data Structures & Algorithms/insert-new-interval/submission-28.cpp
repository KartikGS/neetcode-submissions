class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	int n = intervals.size();
	int l =0, r=n-1;
	while(l<=r){
	int m = l+(r-l)/2;
	if(intervals[m][0]<=newInterval[0]) l = m+1;
	else r=m-1;
}
intervals.insert(intervals.begin()+l, newInterval);
vector<vector<int>> res;
for(int i = 0; i<=n; i++){
	if(res.empty() || res.back()[1]<intervals[i][0]) res.push_back(intervals[i]);
	else {
	res.back()[1] = max(res.back()[1], intervals[i][1]);
}
}
return res;
}
};
