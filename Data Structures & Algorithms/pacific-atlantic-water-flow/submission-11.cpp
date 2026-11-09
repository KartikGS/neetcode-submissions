class Solution {
public:
	vector<pair<int, int>> drc = {{1,0}, {-1,0}, {0,1}, {0,-1}};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
	int rows = heights.size(), cols = heights[0].size();
	vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
	vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
	queue<pair<int, int>> pq;
	queue<pair<int, int>> aq;

	for(int r = 0; r<rows; r++){
	pq.push({r, 0});
	pacific[r][0] = true;
	aq.push({r, cols-1});
	atlantic[r][cols-1] = true;
}

for(int c = 0; c<cols; c++){
	pq.push({0, c});
	pacific[0][c] = true;
	aq.push({rows-1, c});
	atlantic[rows-1][c] = true;
}

bfs(pq, pacific, heights);
bfs(aq, atlantic, heights);

vector<vector<int>> ans;

for(int r = 0; r<rows; r++){
	for(int c=0; c<cols; c++){
		if(pacific[r][c] && atlantic[r][c]) ans.push_back({r,c});
}
}

return ans;
}

void bfs(queue<pair<int, int>> q, vector<vector<bool>>& ocean, const vector<vector<int>>& heights){	
	while(!q.empty()){
	pair<int, int> cell = q.front();
	q.pop();
	int r = cell.first, c = cell.second;
for(pair<int, int> d: drc){
	int nr = r+d.first, nc = c+d.second;
	if(nr<0 || nc<0 || nr>=heights.size() || nc>=heights[0].size() || ocean[nr][nc] || heights[nr][nc]<heights[r][c]) continue;
	q.push({nr, nc});
	ocean[nr][nc] = true;
}

}

return;
}
};

