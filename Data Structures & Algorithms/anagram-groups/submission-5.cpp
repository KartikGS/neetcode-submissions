class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> res;

        for(const string& str: strs){
            vector<int> cnt(26);
            for(const char& c: str) cnt[c-'a']++;
            string key = "";
            for(int i=0; i<26; i++){
                key+=to_string(cnt[i])+",";
            }
            if(mp.count(key)) res[mp[key]].push_back(str);
            else{
                mp[key] = res.size();
                res.push_back({str});
            }
        }

        return res;
    }
};
