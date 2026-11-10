class Solution {
public:
	vector<vector<int>> memo;

int uniquePaths(int m, int n) {
	if(m<n) swap(m, n);

	vector<int> dp(n, 1);
	
	for(int i = m-2; i>=0; i--){
	for(int j = n-2; j>=0; j--){
	dp[j] = dp[j+1]+dp[j];
}
}

return dp[0];
}
};
