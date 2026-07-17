class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);

        for(int i = 1; i<=amount; i++){
            int res = INT_MAX;
            for(int coin: coins){
                if(i-coin>=0 && dp[i-coin]!=INT_MAX){
                    res = min(res, 1+dp[i-coin]);
                }
            }
            dp[i] = res;
        }

        return dp[amount] == INT_MAX?-1:dp[amount];
    }
};
