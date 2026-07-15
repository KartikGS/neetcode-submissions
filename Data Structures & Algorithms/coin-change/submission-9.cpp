class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
	
	for(int i = 1; i<amount+1; i++){
		int mc = INT_MAX;
		for(int c: coins){
			if(i-c>=0 && dp[i-c] != INT_MAX){
	mc = min(mc, 1+dp[i-c]);
}
}
dp[i] = mc;
}
return dp[amount]==INT_MAX?-1:dp[amount];
    }
};



