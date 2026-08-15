class Solution {
public:
    vector<pair<int, int>> drc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rows = heights.size(), cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int i = 0; i<rows; i++){
            dfs(i, 0, pacific, heights);
            dfs(i, cols-1, atlantic, heights);
        }

        for(int i = 0; i<cols; i++){
            dfs(0, i, pacific, heights);
            dfs(rows-1, i, atlantic, heights);
        }

        vector<vector<int>> res;

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[r][c] = true;
        for(pair<int, int> d: drc){
            int nr = r+d.first, nc = c+d.second;
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && heights[nr][nc]>=heights[r][c] && !ocean[nr][nc]) dfs(nr, nc, ocean, heights);
        }
    }
};
