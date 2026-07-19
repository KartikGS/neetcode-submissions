class Solution {
public:
	vector<pair<int, int>> drc = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
    	bool exist(vector<vector<char>>& board, string word) {
        		int rows = board.size();
		int cols = board[0].size();

		for(int r=0; r<rows; r++){
			for(int c =0; c<cols; c++){
				if(dfs(board, word, 0, r, c)) return true;
}
}

return false;
    	}
	
	bool dfs(vector<vector<char>>& board, string word, int idx, int r, int c){
		if(idx == word.size()) return true;
		if( r<0 || r>= board.size() || c<0 || c>=board[0].size() || board[r][c] != word[idx] || board[r][c]=='#') return false;

		board[r][c] = '#';
		for(pair<int, int> d: drc){
			if(dfs(board, word, idx+1, r+d.first, c+d.second)) return true;
}
board[r][c] = word[idx];

return false;
}
};



