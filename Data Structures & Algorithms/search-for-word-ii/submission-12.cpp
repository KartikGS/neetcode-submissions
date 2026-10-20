class TrieNode{
	public:
		unordered_map<char, TrieNode*> children;
		bool word = false;

		void addWord(const string& word){
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
	vector<vector<bool>> visited;

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	TrieNode* root = new TrieNode();
	for(const string& word: words) root->addWord(word);

	int n = board.size(), m = board[0].size();
	visited.resize(n, vector<bool>(m, false));

	set<string> res;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			dfs(i, j, root, board, "", res);
}
}
	
	return vector<string>(res.begin(), res.end());
}

void dfs(int i, int j, TrieNode* root, const vector<vector<char>>& board, string word, set<string>& res){
	if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j] || !root->children.count(board[i][j])) return;
	
	visited[i][j] = true;
	TrieNode* node = root->children[board[i][j]];
	string tmp = word+board[i][j];
	if(node->word){
	res.insert(tmp);
}

dfs(i+1, j, node, board, tmp, res);
dfs(i-1, j, node, board, tmp, res);
dfs(i, j+1, node, board, tmp, res);
dfs(i, j-1, node, board, tmp, res);

	visited[i][j] = false;
}
};


