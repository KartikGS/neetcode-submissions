class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> cnt(26);
        
        int l = 0, r = 0, res = 0, maxFreq, subLen;
        
        while(r<s.size()){
            cnt[s[r]-'A']++;
            maxFreq = *max_element(cnt.begin(), cnt.end());
            subLen = r-l+1;
            // cout<<maxFreq<<" "<<subLen<<"\n";
            if(subLen-maxFreq<=k){
                res = max(res, subLen);
            } else {
                while(subLen-maxFreq>k){
                    cnt[s[l]-'A']--;
                    l++;
                    maxFreq = *max_element(cnt.begin(), cnt.end());
                    subLen = r-l+1;
                }
            }
            r++;
        }
        
        return res;
    }
};
