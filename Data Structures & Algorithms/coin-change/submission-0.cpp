class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int change = dfs(coins, amount, 0);
        return change==10001?-1:change;
    }

    int dfs(vector<int>& coins, int amount, int i){
        if(i>=coins.size()) return 10001;
        if(amount<0) return 10001;
        if(amount == 0) return 0;

        return min(1+dfs(coins, amount-coins[i], i), dfs(coins, amount, i+1));
    }
};
//8 - 5, 4, 1, 
//3, 3 ones, 4 coins, 2 coins