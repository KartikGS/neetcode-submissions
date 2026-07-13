class Solution {
public:
    vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1 , text2, 0, 0);
    }

    int dfs(string t1, string t2, int i, int j){
        if(t1.size() == i || t2.size() == j) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        if(t1[i] == t2[j]){ 
            memo[i][j] = 1+dfs(t1, t2, i+1, j+1);
            return memo[i][j];
        }

        memo[i][j] = max(dfs(t1, t2, i+1, j), dfs(t1, t2, i, j+1));
        return memo[i][j];
    }
};
