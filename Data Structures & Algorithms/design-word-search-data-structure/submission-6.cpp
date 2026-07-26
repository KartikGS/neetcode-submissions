class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
    TrieNode* root;

    bool dfs(string word, TrieNode* root, int idx){
        TrieNode* cur = root;
        for(int i = idx; i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(pair<char, TrieNode*> item: cur->children){
                    if(dfs(word, item.second, i+1)) return true;
                }
                return false;
            } else {
                if(cur->children.find(c) == cur->children.end()) return false;
                cur = cur->children[c];
            }
        }
        return cur->word;
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c: word){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, root, 0);
    }
};
