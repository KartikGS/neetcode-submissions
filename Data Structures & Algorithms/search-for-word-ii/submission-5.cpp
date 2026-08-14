class TrieNode{
    public:
    unordered_map<char, TrieNode*> children;
    bool word;

    void add(const string& word){
        TrieNode* cur = this;
        for(const char& c: word){
            if(cur->children.find(c) == cur->children.end()) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = true;
    }
};

class Solution {
public:
    unordered_set<string> res;
    vector<vector<bool>> visiting;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(const string& word: words) root->add(word);

        int rows = board.size(), cols = board[0].size();

        res.clear();
        visiting.resize(rows, vector<bool>(cols, false));

        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                dfs(r, c, board, root, "");
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void dfs(int r, int c, const vector<vector<char>>& board, TrieNode* cur, string word){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || cur->children.find(board[r][c]) == cur->children.end() || visiting[r][c]) return;

        word+=board[r][c];
        TrieNode* nxt = cur->children[board[r][c]];
        if(nxt->word) res.insert(word);

        visiting[r][c] = true;
        dfs(r+1, c, board, nxt, word);
        dfs(r-1, c, board, nxt, word);
        dfs(r, c+1, board, nxt, word);
        dfs(r, c-1, board, nxt, word);
        visiting[r][c] = false;

        return;
    }
};
