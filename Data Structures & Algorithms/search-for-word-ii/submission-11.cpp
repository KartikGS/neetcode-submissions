class TrieNode{
	public:
		unordered_map<char, TrieNode*> children;
		int ref = 0;
		int idx = -1;

		void add(const string& word, int idx){
	TrieNode* cur = this;
	cur->ref++;
	for(char c: word){
	if(!cur->children.count(c)) cur->children[c] = new TrieNode();
	cur = cur->children[c];
	cur->ref++;
}
cur->idx = idx;
}
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        		TrieNode* root = new TrieNode();
		for(int i = 0; i<words.size(); i++) root->add(words[i], i);
		
		int rows = board.size();
		int cols = board[0].size();

		vector<string> res;

		for(int r = 0; r<rows; r++){
	for(int c = 0; c<cols; c++){
	root->ref-=dfs(r, c, root, board, res, words);
}
}

return res;
    	}

	int dfs(int r, int c, TrieNode* root, vector<vector<char>>& board, vector<string>& res, const vector<string>& words){
		if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='*' || !root->children.count(board[r][c])) return 0;
		
		TrieNode* node = root->children[board[r][c]];
		int total = 0;
if(node->idx != -1){ 
res.push_back(words[node->idx]);
node->idx = -1;
total++;
}
		
		char tmp = board[r][c];
		board[r][c] = '*';

		total+=dfs(r+1, c, node, board, res, words);
		total+=dfs(r-1, c, node, board, res, words);
		total+=dfs(r, c+1, node, board, res, words);
		total+=dfs(r, c-1, node, board, res, words);

board[r][c] = tmp;

node->ref-=total;
if(node->ref == 0){
	root->children.erase(tmp);
}

return total;
}
};
