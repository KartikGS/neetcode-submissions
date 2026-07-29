class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

		for(int i = m-2; i>=0; i--){
			for(int j = n-2; j>=0; j--){
				dp[i][j] = dp[i+1][j] + dp[i][j+1];
			}
		}

		return dp[0][0];
    }
};

// 21 15 10 6 3 1
// 6 5 4 3 2 1
// 1 1 1 1 1 1
