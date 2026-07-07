class Solution {
public:
    vector<int> dp{vector<int>(46, -1)};
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        dp[n] = climbStairs(n-1)+climbStairs(n-2);
        return dp[n];
    }
};
