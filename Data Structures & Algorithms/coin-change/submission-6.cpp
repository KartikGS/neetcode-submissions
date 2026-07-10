class Solution {
public:
    vector<int> memo;

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        memo.resize(amount, -1);
        int res = dfs(coins, amount);
        return res==INT_MAX?-1:res;
    }

    int dfs(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(memo[amount-1] != -1) return memo[amount-1];

        int res = INT_MAX;

        for(int coin: coins){
            int temp = dfs(coins, amount-coin);
            if(temp!=INT_MAX) res = min(res, 1+temp);
        }
        memo[amount-1] = res;
        return res;
    }
};
