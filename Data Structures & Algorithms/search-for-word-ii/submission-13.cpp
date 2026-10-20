class TrieNode{
	public:
		unordered_map<char, TrieNode*> children;
		int refs = 0;
		int idx = -1;

		void addWord(const string& word, int idx){
	TrieNode* cur = this;
	cur->refs++;
	for(char c: word){
	if(!cur->children.count(c)){
	cur->children[c] = new TrieNode();
}
cur = cur->children[c];
cur->refs++;
}
cur->idx = idx;
}
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	TrieNode* root = new TrieNode();
	for(int i = 0; i<words.size(); i++) root->addWord(words[i], i);

	int n = board.size(), m = board[0].size();
	vector<string> res;

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			root->refs -= dfs(i, j, root, board, res, words);
}
}
	
	return res;
}

int dfs(int i, int j, TrieNode* root, vector<vector<char>>& board, vector<string>& res, const vector<string>& words){
	if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == '*' || !root->children.count(board[i][j])) return 0;
	
	char tmp = board[i][j];
	board[i][j] = '*';
	TrieNode* node = root->children[tmp];
	int total = 0;
if(node->idx != -1){
	res.push_back(words[node->idx]);
	node->idx = -1;
	total++;
}

total += dfs(i+1, j, node, board, res, words);
total += dfs(i-1, j, node, board, res, words);
total += dfs(i, j+1, node, board, res, words);
total += dfs(i, j-1, node, board, res, words);

node->refs-=total;
if(node->refs==0){
	root->children.erase(tmp);
}

	board[i][j] = tmp;
	return total;
}
};


