class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        vector<int> dp(amount+1,0);
        
        for(int i = 1; i<=amount; i++){
            int tmin = 10001;
            for(auto j: coins){
                if(i-j>=0){
                    tmin = min(tmin, 1+dp[i-j]);
                }
            }
            dp[i] = tmin;
        }

        return dp[amount]>10000?-1:dp[amount];
    }
};
