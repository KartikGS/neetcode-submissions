class TrieNode{
public:
unordered_map<char, TrieNode*> children;
int idx = -1;
int refs = 0;

void addWord(const string word, int idx){
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
	
	int rows = board.size(), cols = board[0].size();
	vector<string> res;
	for(int r = 0; r<rows; r++){
		for(int c=0; c<cols; c++){
			root->refs -= dfs(r, c, root, board, words, res);
		}
	}
	return res;
}

int dfs(int r, int c, TrieNode*& root, vector<vector<char>>& board, const vector<string>& words, vector<string>& res){
	if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='*' || !root->children.count(board[r][c])) return 0;
	
	char tmp = board[r][c];
board[r][c] = '*';
	TrieNode* node = root->children[tmp];
	int total = 0;
	
if(node->idx!=-1){
	res.push_back(words[node->idx]);
	node->idx = -1;
	total++;
}

	total+=dfs(r+1, c, node, board, words, res);
	total+=dfs(r-1, c, node, board, words, res);
	total+=dfs(r, c+1, node, board, words, res);
	total+=dfs(r, c-1, node, board, words, res);
	
board[r][c] = tmp;
node->refs-=total;
if(node->refs == 0){
	root->children.erase(tmp);
}
return total;
}
};


