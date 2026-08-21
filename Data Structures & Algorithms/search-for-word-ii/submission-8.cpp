class TrieNode{
    public:
    unordered_map<char, TrieNode*> children;
    bool word = false;

    void add(string word){
        TrieNode* cur = this;
        for(char c: word){
            if(!cur->children.count(c)) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = true;
    }
};

class Solution {
public:
    vector<vector<bool>> visiting;
    vector<pair<int,int>> drc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word: words) root->add(word);

        int rows = board.size(), cols = board[0].size();

        set<string> res;
        visiting.resize(rows, vector<bool>(cols, false));

        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                dfs(r, c, board, root, res, "");
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* cur, set<string>& res, string word){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || !cur->children.count(board[r][c]) || visiting[r][c]) return;

        TrieNode* node = cur->children[board[r][c]];
        word+=board[r][c];
        if(node->word) res.insert(word);

        visiting[r][c] = true;
        for(pair<int, int> d: drc){
            dfs(r+d.first, c+d.second, board, node, res, word);
        }
        visiting[r][c] = false;

        return;
    }
};
