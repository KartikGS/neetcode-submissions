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
        vector<int> prev(t2+1, 0);
        vector<int> curr(t2+1, 0);

        for(int i=t1-1; i>=0; i--){
            for(int j = t2-1; j>=0; j--){
                if(text1[i] == text2[j]) curr[j] = 1+prev[j+1];
                else curr[j] = max(prev[j],curr[j+1]);
            }
            swap(curr, prev);
        }

        return prev[0];
    }
};
