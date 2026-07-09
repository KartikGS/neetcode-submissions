class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0) return 0;
        unordered_map<char, int> mp;
        int l = 0;
        int ans = 1;
        mp[s[0]] = 0;
        for(int r = 1; r<s.size(); r++){
            if(mp.count(s[r]) && mp[s[r]]>=l){
                l = mp[s[r]]+1;
            }
            mp[s[r]] = r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
