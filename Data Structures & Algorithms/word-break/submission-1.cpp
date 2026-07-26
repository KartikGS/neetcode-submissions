class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool word = false;
};

class Trie{
    TrieNode* root;
    unordered_map<int, bool> dp;

    bool dfs(string word, TrieNode* root, int idx){
        if(idx==word.size()) return true;

        if(dp.find(idx) != dp.end()) return dp[idx];

        TrieNode* cur = root;
        for(int i = idx; i<word.size(); i++){
            char c = word[i];
            if(cur->children.find(c) == cur->children.end()){ 
                dp[idx] = false;
                return false;
            }
            if(cur->children[c]->word && dfs(word, root, i+1)){ 
                dp[idx] = true;
                return true;
            }
            cur = cur->children[c];
        }
        dp[idx] = cur->word;
        return cur->word;
    }
    public:
        Trie(){
            root = new TrieNode();
            dp.clear();
        }

        void add(string word){
            TrieNode* cur = root;
            for(char c: word){
                if(cur->children.find(c) == cur->children.end()){
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->word = true;
        }

        bool search(string word){
            return dfs(word, root, 0);
        }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //Input: s = "applepenapple", wordDict = ["apple","app","lepenapple"]
        Trie trie;
        for(string word: wordDict){
            trie.add(word);
        }
        return trie.search(s);
    }
};
