class Solution {
public:
	vector<int> dp;
    
	int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, -1);
		int res = dfs(coins, amount);
		return res!=INT_MAX?res:-1;
    }

	int dfs(vector<int>& coins, int amount){
		if(amount==0) return 0;
		if(dp[amount]!=-1) return dp[amount];

		int res = INT_MAX;
		for(auto coin:coins){
			if(amount-coin>=0){
				int noc = dfs(coins ,amount-coin);
				if(noc!=INT_MAX){
					res = min(res, 1+noc);
				}
			}
		}
		dp[amount] = res;
		return res;
	}
};
