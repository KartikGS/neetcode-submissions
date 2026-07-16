class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //zxyzxyz
        
        int res = 0;
        int l = 0;
        unordered_map<char, int> cti;//character to index

        for(int r = 0; r<s.size(); r++){
            if(cti.find(s[r]) != cti.end()){
                l = max(l, 1+cti[s[r]]);
            }
            res = max(res, r-l+1);
            cti[s[r]] = r;
        }

        return res;
    }
};
