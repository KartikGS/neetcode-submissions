class TrieNode{
	public:
		unordered_map<char, TrieNode*> children;
		bool word=false;

		void add(const string& word){
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

    	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        		TrieNode* root = new TrieNode();
		for(const string& word: words) root->add(word);
		
		int rows = board.size();
		int cols = board[0].size();

		visiting.resize(rows, vector<bool>(cols, false));

		unordered_set<string> res;

		for(int r = 0; r<rows; r++){
	for(int c = 0; c<cols; c++){
	dfs(r, c, root, board, "", res);
}
}

return vector<string>(res.begin(), res.end());
    	}

	void dfs(int r, int c, TrieNode* root, const vector<vector<char>>& board, string word, unordered_set<string>& res){
		if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || visiting[r][c] || !root->children.count(board[r][c])) return;
		
		word+=board[r][c];
		TrieNode* node = root->children[board[r][c]];
		if(node->word) res.insert(word);
		
		visiting[r][c] = true;

		dfs(r+1, c, node, board, word, res);
		dfs(r-1, c, node, board, word, res);
		dfs(r, c+1, node, board, word, res);
		dfs(r, c-1, node, board, word, res);

visiting[r][c] = false;
}
};
