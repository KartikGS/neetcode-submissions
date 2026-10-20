class Solution {
public:
	int uniquePaths(int m, int n) {
		if(n>m) swap(m, n);
        		vector<int> dp(n, 1);
		for(int i = m-2; i>=0; i--){
	for(int j = n-2; j>=0; j--){
		dp[j] = dp[j+1]+dp[j];
}
}
return dp[0];
    	}
};

