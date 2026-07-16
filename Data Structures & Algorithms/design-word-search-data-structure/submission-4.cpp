class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool word = false;
};

class WordDictionary {
    TrieNode* root;

    bool dfs(string word, int idx, TrieNode* node){
        TrieNode* curr = node;
        for(int i = idx; i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto child: curr->children){
                    if(dfs(word, i+1, child.second)) return true;
                }
                return false;
            }
            if(curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return curr->word;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word){
            if(curr->children.find(c) == curr->children.end()) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->word = true;
        return;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
