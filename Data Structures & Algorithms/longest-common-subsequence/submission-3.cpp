class Solution {
public:
    vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(), vector<int>(text2.size(), -1));
       return dfs(text1, text2, 0, 0); 
    }

    int dfs(string t1, string t2, int i, int j){
        if(i==t1.size() || j==t2.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        int lcs = dfs(t1, t2, i+1, j);

        int k = j;
        while(t2[k]!=t1[i] && k<t2.size()) k++;
        if(k!=t2.size()) lcs = max(lcs, 1+dfs(t1, t2, i+1, k+1));

        memo[i][j] = lcs;
        return lcs;
    }
};
