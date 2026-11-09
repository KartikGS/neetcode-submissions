class Solution {
public:
	vector<pair<int, int>> drc = {{1,0}, {-1,0}, {0,1}, {0,-1}};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
	int rows = heights.size(), cols = heights[0].size();
	vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
	vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

	for(int r = 0; r<rows; r++){
	dfs(r, 0, pacific, heights);
	dfs(r, cols-1, atlantic, heights);
}

for(int c = 0; c<cols; c++){
	dfs(0, c, pacific, heights);
	dfs(rows-1, c, atlantic, heights);
}

vector<vector<int>> ans;

for(int r = 0; r<rows; r++){
	for(int c=0; c<cols; c++){
		if(pacific[r][c] && atlantic[r][c]) ans.push_back({r,c});
}
}

return ans;
}

void dfs(int r, int c, vector<vector<bool>>& ocean, const vector<vector<int>>& heights){	
	ocean[r][c] = true;

for(pair<int, int> d: drc){
	int nr = r+d.first, nc = c+d.second;
	if(nr<0 || nc<0 || nr>=heights.size() || nc>=heights[0].size() || ocean[nr][nc] || heights[nr][nc]<heights[r][c]) continue;
	dfs(nr, nc, ocean, heights);
}

return;
}
};

