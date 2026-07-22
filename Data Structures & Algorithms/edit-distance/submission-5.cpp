class Solution {
public:
	vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        int m = word1.size();
		int n = word2.size();
		memo.resize(m, vector<int>(n, -1));
		return dfs(word1, word2, m, n, 0, 0);
    }

	int dfs(string word1, string word2, int m, int n, int i, int j){
		if(i==m) return n-j;
		if(j==n) return m-i;
		if(memo[i][j]!=-1) return memo[i][j];
		if(word1[i] == word2[j]){
			memo[i][j] = dfs(word1, word2, m, n, i+1, j+1);
		} else {
			memo[i][j] = 1+min({dfs(word1, word2, m, n, i+1, j+1), dfs(word1, word2, m, n, i+1, j), dfs(word1, word2, m, n, i, j+1)});
		}
		return memo[i][j];
	}
};
