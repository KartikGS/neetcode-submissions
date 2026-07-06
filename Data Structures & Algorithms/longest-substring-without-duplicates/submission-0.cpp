class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> lastOcr;

        int j = 0;
        for(int i = 0; i<s.size(); i++){
            if(lastOcr.count(s[i])){
                maxLen = max(maxLen, i-j);
                int lol = lastOcr[s[i]];
                while(j<=lol){
                    lastOcr.erase(s[j]);
                    j++;
                }
            }
            lastOcr[s[i]] = i;
        }

        return max(maxLen, int(s.size()-j));
    }
};
