class Solution {
public:
    int dp[45];
    int climbStairs(int n) {
        if (n==1) {
            dp[0] = 1;
            return 1;
            };
        if (n==2){ 
            dp[1] = 2;
            return 2;
        }
        if(dp[n-1]) return dp[n-1];
        dp[n-1] = climbStairs(n-1)+climbStairs(n-2);
        return dp[n-1];
    }
};
