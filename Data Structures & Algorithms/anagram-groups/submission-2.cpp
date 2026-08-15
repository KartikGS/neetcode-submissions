class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            string srt = s;
            sort(srt.begin(), srt.end());
            mp[srt].push_back(s);
        }
        vector<vector<string>> res;
        for(pair<string,vector<string>> item: mp) res.push_back(item.second);
        return res;
    }
};
