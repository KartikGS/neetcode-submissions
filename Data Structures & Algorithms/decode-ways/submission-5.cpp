class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), dp, dp1 = 1, dp2;
        for(int i = n-1; i>=0; i--){
            dp=0;
            if(s[i]!='0') dp += dp1;
            if(i != n-1 && (s[i] == '1' || (s[i]=='2' && s[i+1]<'7'))) dp += dp2;
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};
