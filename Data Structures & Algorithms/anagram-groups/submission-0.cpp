class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> srt = strs;
        for(string& s: srt) sort(s.begin(), s.end());

        unordered_map<string, int> mp;
        vector<vector<string>> res;

        for(int i = 0; i<strs.size(); i++){
            if(mp.find(srt[i])==mp.end()){
                res.push_back({strs[i]});
                mp[srt[i]] = res.size()-1;
            } else {
                res[mp[srt[i]]].push_back(strs[i]);
            }
        }

        return res;
    }
};
