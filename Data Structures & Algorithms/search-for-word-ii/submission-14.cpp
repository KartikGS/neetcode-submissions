class TrieNode{
public:
unordered_map<char, TrieNode*> children;
bool word;

void addWord(const string word){
	TrieNode* cur = this;
	for(char c: word){
	if(!cur->children.count(c)){
	cur->children[c] = new TrieNode();
}
cur = cur->children[c];
}
cur->word = true;
}
};

class Solution {
public:
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	TrieNode* root = new TrieNode();
	for(const string word: words) root->addWord(word);
	
	int rows = board.size(), cols = board[0].size();
	set<string> res;
	vector<vector<bool>> visiting(rows, vector<bool>(cols, false));
	for(int r = 0; r<rows; r++){
		for(int c=0; c<cols; c++){
			dfs(r, c, root, board, "", visiting, res);
		}
	}
	return vector<string>(res.begin(), res.end());
}

void dfs(int r, int c, TrieNode* root,  const vector<vector<char>>& board, string word, vector<vector<bool>>& visiting, set<string>& res){
	if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || visiting[r][c] || !root->children.count(board[r][c])) return;
	
	visiting[r][c] = true;
	word+=board[r][c];
	TrieNode* node = root->children[board[r][c]];
	
if(node->word){
	res.insert(word);
}

	dfs(r+1, c, node, board, word, visiting, res);
	dfs(r-1, c, node, board, word, visiting, res);
	dfs(r, c+1, node, board, word, visiting, res);
	dfs(r, c-1, node, board, word, visiting, res);
	
visiting[r][c] = false;
}
};


