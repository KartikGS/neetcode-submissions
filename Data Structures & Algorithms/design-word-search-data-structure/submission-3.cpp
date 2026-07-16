class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c:word){
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i<word.size(); i++){
            if(word[i] == '.'){
                return wildcard(word, i, curr);
            } else if(curr->children.find(word[i]) == curr->children.end()){
                return false;
            } else{
                curr = curr->children[word[i]];
            }
        }
        return curr->endOfWord;
    }

    bool wildcard(string word, int idx, TrieNode* start){
        // if(idx == word.size()) return false;
        TrieNode* curr = start;
        for(int i = idx; i<word.size(); i++){
            if(word[i] == '.'){
                // if(curr->children.empty()) return false;
                for(auto child: curr->children){
                    if(wildcard(word, i+1, child.second)) return true;
                }
                return false;
            } else {
                if(curr->children.find(word[i]) == curr->children.end()) return false;
                curr = curr->children[word[i]];
            }
        }
        return curr->endOfWord;
    }
};
