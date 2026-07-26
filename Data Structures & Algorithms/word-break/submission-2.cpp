class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, bool> memo;
    int t;

    bool wordBreak(string s, vector<string>& wordDict) {
        dict.clear();
        t=0;
        for(string word: wordDict){ 
            dict.insert(word);
            t = max(t, (int)word.size());
        }
        memo[s.size()] = true;
        return dfs(s, 0);
    }

    bool dfs(string s, int idx){
        if(memo.find(idx)!=memo.end()) return memo[idx];

        for(int j=idx; j<min((int)s.size(), idx+t); j++){
            if(dict.find(s.substr(idx, j-idx+1)) != dict.end()){
                if(dfs(s, j+1)){
                    memo[idx] = true;
                    return true;
                }
            }
        }

        memo[idx] = false;
        return false;
    }
};
