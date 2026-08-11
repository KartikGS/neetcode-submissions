vector<pair<int, int>> drc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord = false;
        string word;
};

class Trie{
    TrieNode* root;
    vector<vector<bool>> visiting;

    void dfs(int r, int c, TrieNode* cur, const vector<vector<char>>& board, set<string>& res, vector<vector<bool>>& visiting){
        if(visiting[r][c]) return;

        if(cur->endOfWord) res.insert(cur->word);

        visiting[r][c] = true;

        for(const pair<int, int>& d:drc){
            int nr = r+d.first, nc = c+d.second;
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && cur->children.find(board[nr][nc]) != cur->children.end()){
                dfs(nr, nc, cur->children[board[nr][nc]], board, res, visiting);
            }
        }

        visiting[r][c] = false;
        
        return;
    }

    public:
        Trie(){
            root = new TrieNode();
        }

        void add(const string& word){
            TrieNode* cur = root;
            for(const char& c: word){
                if(cur->children.find(c) == cur->children.end()){
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->endOfWord = true;
            cur->word = word;
        }

        vector<string> search(vector<vector<char>>& board){
            set<string> res;
            const int rows = board.size(), cols = board[0].size();
            visiting.resize(rows, vector<bool>(cols, false));

            for(int i = 0; i<rows; i++){
                for(int j = 0; j<cols; j++){
                    if(root->children.find(board[i][j]) != root->children.end()){
                        dfs(i, j, root->children[board[i][j]], board, res, visiting);
                    }
                }
            }

            return vector<string>(res.begin(), res.end());
        }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(const string& word: words) trie.add(word);
        return trie.search(board);
    }
};
