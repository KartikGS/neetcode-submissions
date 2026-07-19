class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool word = false;
};

class WordDictionary {
    TrieNode* root;

    bool dfs(string word, TrieNode* root, int idx){
        TrieNode* curr = root;
        for(int i=idx; i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto child: curr->children){
                    if(dfs(word, child.second, i+1)) return true;
                }
                return false;
            } else {
                if(curr->children.find(c) == curr->children.end()) return false;
                curr = curr->children[c];
            }
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
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return dfs(word, root, 0);
    }
};
