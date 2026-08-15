class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<vector<int>, int> mp;
        
        for(const string& s: strs){
            vector<int> tmp(26,0);
            for(const char& c: s) tmp[c-'a']++;
            if(mp.count(tmp)) res[mp[tmp]].push_back(s);
            else{
                res.push_back({s});
                mp[tmp] = res.size()-1;
            }
        }

        return res;
    }
};
//act
//