class Solution {
public:

	vector<pair<int, int>> drc = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size(), cols = heights[0].size();
		
		vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
		vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

		for(int i = 0; i<rows; i++){
			if(!pacific[i][0]) dfs(i, 0, pacific, heights);
			if(!atlantic[i][cols-1]) dfs(i, cols-1, atlantic, heights);
		}
		for(int i = 0; i<cols; i++){
			if(!pacific[0][i]) dfs(0, i, pacific, heights);
			if(!atlantic[rows-1][i]) dfs(rows-1, i, atlantic, heights);
		}

		vector<vector<int>> res;
		
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				if(atlantic[i][j] && pacific[i][j]) res.push_back({i, j});
			}
		}

		return res;
    }

	void dfs(const int& r, const int& c, vector<vector<bool>>& flows, const vector<vector<int>>& heights){
		if(flows[r][c]) return;

		flows[r][c] = true;

		for(const pair<int, int>& d: drc){
			int nr = r+d.first;
			int nc = c+d.second;
			if(nr>=0 & nc>=0 && nr<heights.size() && nc<heights[0].size() && heights[r][c]<=heights[nr][nc]){
				dfs(nr, nc, flows, heights);
			}
		}

		return;
	}
};
