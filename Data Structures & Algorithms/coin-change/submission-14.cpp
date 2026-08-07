class Solution {
public:
    	int coinChange(vector<int>& coins, int amount) {
        		vector<int> dp(amount+1, -1);
		dp[0] = 0;

		for(int i=1; i<=amount; i++){
			int mc = INT_MAX;
	for(int coin: coins){
	if(i-coin>=0 && dp[i-coin]!=-1){
	mc = min(mc, 1+dp[i-coin]);
}
}
dp[i] = mc==INT_MAX?-1:mc;
}

		return dp[amount];
}
};
