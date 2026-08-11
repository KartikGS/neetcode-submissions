class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool word = false;

        void add(const string& word){
            TrieNode* cur = this;
            for(const char& c: word){
                if(!cur->children.count(c)) cur->children[c] = new TrieNode();
                cur = cur->children[c];
            }
            cur->word = true;
        }
};

class Solution {
public:
    vector<vector<bool>> visit;
    unordered_set<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(const string& word: words) root->add(word);

        int rows = board.size(), cols = board[0].size();
        visit.resize(rows, vector<bool>(cols, false));
        res.clear();

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                dfs(i, j, root, board, "");
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void dfs(int r, int c, TrieNode* node, const vector<vector<char>>& board, string word){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || !node->children.count(board[r][c]) || visit[r][c]) return;

        word+=board[r][c];
        node = node->children[board[r][c]];
        if(node->word) res.insert(word);

        visit[r][c] = true;
        dfs(r+1, c, node, board, word);
        dfs(r-1, c, node, board, word);
        dfs(r, c+1, node, board, word);
        dfs(r, c-1, node, board, word);
        visit[r][c] = false;

        return;
    }
};
