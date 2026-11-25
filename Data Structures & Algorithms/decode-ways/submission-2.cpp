class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;

        int n = s.size();

        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 1; i<n; i++){
            if(s[i] == '0' && (s[i-1]>'2' || s[i-1]=='0')) return 0;
            else{
                if(s[i]!='0') {
                    dp[i+1] += dp[i];
                }
                string ss = s.substr(i-1,2);
                if(ss<"27" && ss>="10") dp[i+1]+=dp[i-1];
            }
        }

        return dp[n];
    }
};
