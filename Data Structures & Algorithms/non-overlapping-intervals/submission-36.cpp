class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    		sort(intervals.begin(), intervals.end());
		int n = intervals.size();
		int res = 0, end = intervals[0][1];
		for(int i = 1; i<n; i++){
	if(intervals[i][0]<end){
	res++;
	end = min(end, intervals[i][1]);
} else {
	end = intervals[i][1];
}
}
return res;
    	}
};
