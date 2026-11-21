class Solution {
public:
	
	vector<pair<int, int>> drc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
	int rows = heights.size(), cols = heights[0].size();
	
vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
	vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

	for(int i = 0; i<cols; i++){
	dfs(0, i, pacific, heights);
	dfs(rows-1, i, atlantic, heights);
}

for(int i = 0; i<rows; i++){
	dfs(i, 0, pacific, heights);
	dfs(i, cols-1, atlantic, heights);
}

vector<vector<int>> res;

for(int r = 0; r<rows; r++){
	for(int c = 0; c<cols; c++){
		if(pacific[r][c] && atlantic[r][c]) res.push_back({r,c});
	}
}

return res;
}

void dfs(int r, int c, vector<vector<bool>>& ocean, const vector<vector<int>>& heights){
	ocean[r][c] = true;
	for(pair<int, int> d:drc){
	int nr = r+d.first, nc = c+d.second;
	if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && !ocean[nr][nc] && heights[nr][nc]>=heights[r][c]) dfs(nr, nc, ocean, heights);
}
}
};
//rows = 3, cols = 5
//pacific 0,0    1,0
//atlantic
