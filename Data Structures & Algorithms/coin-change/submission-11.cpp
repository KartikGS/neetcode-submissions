class Solution {
public:
    unordered_map<int, int> memo;

    int coinChange(vector<int>& coins, int amount) {
        //8 - 5, 4, 1
        int res = dfs(coins, amount);
        return res == INT_MAX?-1:res;
    }

    int dfs(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(memo.find(amount) != memo.end()) return memo[amount];

        int res = INT_MAX;
        for(int coin: coins){
            int temp = dfs(coins, amount-coin);
            if(temp!=INT_MAX) res = min(res, 1+temp);
        }
        memo[amount] = res;
        return res;
    }
};
