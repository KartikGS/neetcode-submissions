class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lo; //last occurence
        int l = 0, res = 0;

        for(int r = 0;r<s.size(); r++){
            if(lo.find(s[r]) != lo.end()){
                l= max(l, lo[s[r]]+1);
            }
            res = max(res, r-l+1);
            lo[s[r]] = r;
        }
        return res;
    }
};
