class Solution {
public:
	vector<vector<int>> memo;
    int uniquePaths(int m, int n) {
		memo.resize(m+1, vector<int>(n+1, -1));
        return dfs(1, 1, m, n);
    }
	int dfs(int i, int j, int m, int n){
		if(i>m || j>n) return 0;
		if(i==m || j==n) return 1;
		if(memo[i][j] != -1) return memo[i][j];
		memo[i][j] = dfs(i+1, j, m, n) + dfs(i, j+1, m, n);
		return memo[i][j];
	}
};
