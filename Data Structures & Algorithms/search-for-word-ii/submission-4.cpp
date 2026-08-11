class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        int idx = -1;
        int refs = 0;

        void add(const string& word, int i){
            TrieNode* cur = this;
            cur->refs++;
            for(const char& c: word){
                if(!cur->children.count(c)) cur->children[c] = new TrieNode();
                cur = cur->children[c];
                cur->refs++;
            }
            cur->idx = i;
        }
};

class Solution {
public:
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i<words.size(); i++) root->add(words[i], i);

        int rows = board.size(), cols = board[0].size();
        res.clear();

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                root->refs -= dfs(i, j, root, board, words);
            }
        }

        return res;
    }

    int dfs(int r, int c, TrieNode* node, vector<vector<char>>& board, const vector<string>& words){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || !node->children.count(board[r][c])) return 0;

        char tmpChar = board[r][c];
        TrieNode* tmpNode = node;
        node = node->children[board[r][c]];
        int count = 0;
        if(node->idx != -1) {
            res.push_back(words[node->idx]);
            node->idx = -1;
            count++;
        }

        board[r][c] = '*';
        count+=dfs(r+1, c, node, board, words);
        count+=dfs(r-1, c, node, board, words);
        count+=dfs(r, c+1, node, board, words);
        count+=dfs(r, c-1, node, board, words);
        board[r][c] = tmpChar;

        node->refs -= count;
        if(!node->refs){
            tmpNode->children.erase(tmpChar);
        }

        return count;
    }
};
