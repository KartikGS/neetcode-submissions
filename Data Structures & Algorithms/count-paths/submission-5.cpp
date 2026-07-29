class Solution {
public:
	vector<vector<int>> memo;

    int uniquePaths(int m, int n) {
		memo.resize(m, vector<int>(n, -1));
        return dfs(0, 0, m, n);
    }

	int dfs(int i, int j, int m, int n){
		if(i==m || j==n) return 0;
		
		if(i==m-1 || j== n-1) return 1;

		if(memo[i][j] != -1) return memo[i][j];

		memo[i][j] = dfs(i+1, j, m, n) + dfs(i, j+1, m, n);

		return memo[i][j];
	}
};
