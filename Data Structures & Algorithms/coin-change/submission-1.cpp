class Solution {
public:
    vector<vector<int>> dp;

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, vector<int>(coins.size(), -1));
        int change = dfs(coins, amount, 0);
        return change==10001?-1:change;
    }

    int dfs(vector<int>& coins, int amount, int i){
        if(i>=coins.size()) return 10001;
        if(amount<0) return 10001;
        if(amount == 0) return 0;
        if(dp[amount][i]!=-1) return dp[amount][i];

        dp[amount][i] = min(1+dfs(coins, amount-coins[i], i), dfs(coins, amount, i+1));
        return dp[amount][i];
    }
};
//8 - 5, 4, 1, 
//3, 3 ones, 4 coins, 2 coins