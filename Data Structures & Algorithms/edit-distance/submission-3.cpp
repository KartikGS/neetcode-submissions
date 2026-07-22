class Solution {
public:
	int minDistance(string word1, string word2) {
		if(word1.size()<word2.size()) swap(word1, word2);
	
int w1 = word1.size(), w2 = word2.size();
vector<int> dp(w2+1, 0);

for(int j = 0; j<w2; j++) dp[j] = w2-j;
		
		for(int i = w1-1; i>=0; i-- ){
			int diag = w1-i-1;
			dp[w2] = w1-i;
			for(int j=w2-1;j>=0; j--){
				int temp = dp[j];
	if(word1[i] == word2[j]) dp[j] = diag;
	else{
		dp[j] = 1+min({diag, dp[j], dp[j+1]});
}
diag = temp;
}
}
return dp[0];
    	}
// temp 0;
	// 0 0 3 2 1 1
};
