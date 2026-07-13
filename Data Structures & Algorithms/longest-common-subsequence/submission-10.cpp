class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();
        if(t2>t1){
            swap(text1, text2);
        }
        t1 = text1.size();
        t2 = text2.size();
        vector<int> dp(t2+1, 0);

        for(int i=t1-1; i>=0; i--){
            int prev = 0;
            for(int j = t2-1; j>=0; j--){
                int temp = dp[j];

                if(text1[i] == text2[j]) dp[j] = 1+prev;
                else dp[j] = max(dp[j],dp[j+1]);

                prev = temp;
            }
            
        }

        return dp[0];
    }
};
