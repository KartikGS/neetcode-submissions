class Solution {
    
    vector<pair<int, int>> drc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(int r, int c, vector<vector<char>>& grid){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == '0') return;
        grid[r][c] = '0';
        for(pair<int, int> d: drc){
            int nr = r+d.first;
            int nc = c+d.second;
            dfs(nr, nc, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int r = 0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == '1'){
                    res++;
                    dfs(r, c, grid);
                }
            }
        }

        return res;
    }
};
