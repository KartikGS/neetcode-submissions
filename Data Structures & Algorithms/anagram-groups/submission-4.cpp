class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            
            vector<int> cnt(26);
            for(char c: s) cnt[c-'a']++;
            
            string key = to_string(cnt[0]);
            for(int i =1; i<26; i++) key+=','+to_string(cnt[i]);

            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(pair<string,vector<string>> item: mp) res.push_back(item.second);
        return res;
    }
};
