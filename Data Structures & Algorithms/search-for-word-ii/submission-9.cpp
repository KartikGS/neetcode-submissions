class TrieNode{
    public:
    unordered_map<char, TrieNode*> children;
    int refs = 0;
    int idx = -1;

    void add(string word, int idx){
        TrieNode* cur = this;
        cur->refs++;
        for(char c: word){
            if(!cur->children.count(c)) cur->children[c] = new TrieNode();
            cur = cur->children[c];
            cur->refs++;
        }
        cur->idx = idx;
    }
};

class Solution {
public:
    vector<pair<int,int>> drc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i<words.size(); i++) root->add(words[i], i);

        int rows = board.size(), cols = board[0].size();

        vector<string> res;
        
        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                root->refs-=dfs(r, c, board, root, res, words);
            }
        }

        return res;
    }

    int dfs(int r, int c, vector<vector<char>>& board, TrieNode* cur, vector<string>& res, vector<string>& words){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || !cur->children.count(board[r][c]) || board[r][c] == '*') return 0;

        TrieNode* node = cur->children[board[r][c]];
        int total = 0;
        if(node->idx!=-1) {
            total++;
            res.push_back(words[node->idx]);
            node->idx = -1;
        }

        char tmp = board[r][c];
        board[r][c] = '*';
        for(pair<int, int> d: drc){
            total += dfs(r+d.first, c+d.second, board, node, res, words);
        }
        board[r][c] = tmp;

        node->refs-=total;
        if(!node->refs){
            cur->children.erase(tmp);
        }

        return total;
    }
};
