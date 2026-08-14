class TrieNode{
    public:
    unordered_map<char, TrieNode*> children;
    bool word = false;
    int refs = 0;

    void add(const string& word){
        TrieNode* cur = this;
        cur->refs+=1;
        for(const char& c: word){
            if(cur->children.find(c) == cur->children.end()) cur->children[c] = new TrieNode();
            cur = cur->children[c];
            cur->refs+=1;
        }
        cur->word = true;
    }
};

class Solution {
public:
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(const string& word: words) root->add(word);

        int rows = board.size(), cols = board[0].size();

        res.clear();

        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                root->refs-=dfs(r, c, board, root, "");
            }
        }

        return res;
    }

    int dfs(int r, int c, vector<vector<char>>& board, TrieNode*& cur, string word){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || cur->children.find(board[r][c]) == cur->children.end()) return 0;

        word+=board[r][c];
        TrieNode* nxt = cur->children[board[r][c]];

        int found = 0;
        if(nxt->word) {
            res.push_back(word);
            nxt->word = false;
            found++;
        }

        char tmp = board[r][c];
        board[r][c] = '*';
        
        found+=dfs(r+1, c, board, nxt, word);
        found+=dfs(r-1, c, board, nxt, word);
        found+=dfs(r, c+1, board, nxt, word);
        found+=dfs(r, c-1, board, nxt, word);

        nxt->refs-=found;
        if(nxt->refs == 0) cur->children.erase(tmp);
        
        board[r][c] = tmp;

        return found;
    }
};
