class Solution {
public:
	vector<vector<int>> memo;
    	int minDistance(string word1, string word2) {
		memo.resize(word1.size(), vector<int>(word2.size(),-1));
        		return dfs(word1, word2, 0, 0);
    	}
	int dfs(string word1, string word2, int w1, int w2){
		if(w1 == word1.size()) return word2.size()-w2;
		if(w2 == word2.size()) return word1.size()-w1;
		if(memo[w1][w2]!=-1) return memo[w1][w2];

		if(word1[w1] == word2[w2]){ 
memo[w1][w2] = dfs(word1, word2, w1+1, w2+1);
return memo[w1][w2];
}

		memo[w1][w2] = 1+min({dfs(word1, word2, w1+1, w2+1), dfs(word1, word2, w1+1, w2), dfs(word1, word2, w1, w2+1)});
		return memo[w1][w2];
}
};

//max ops = max(len word1, len word2)
//if same move
// add ->len word 1 < len word 2(dont 
// replace -> len word 1 = len word 2->explore add remove
//remove
//aplle 2
//allepaasdf = 2
