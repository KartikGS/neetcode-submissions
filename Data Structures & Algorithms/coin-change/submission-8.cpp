class Solution {
public:
	vector<int> memo;
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount+1, -1);
        int mCoins = dfs(coins, amount);
        return mCoins==INT_MAX?-1:mCoins;
    }

    int dfs(vector<int>& coins, int amount){
        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;
        if(memo[amount] != -1) return memo[amount];

        int minCoins = INT_MAX;
        for(int coin: coins){
	        int currCoins = dfs(coins, amount - coin);
	        if(currCoins!=INT_MAX) minCoins = min(minCoins, 1+currCoins);
        }    
        memo[amount] = minCoins;

        return minCoins;
    }
};
