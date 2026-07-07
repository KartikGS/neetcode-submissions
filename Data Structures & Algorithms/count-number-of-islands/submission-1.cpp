class Solution {
public:
    void markIsland(vector<vector<char>>& grid, int r, int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c] != '1') return;
        
        grid[r][c] = '2';
        
        markIsland(grid, r+1, c);
        markIsland(grid, r-1, c);
        markIsland(grid, r, c+1);
        markIsland(grid, r, c-1);
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        
        for(int r = 0; r<rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == '1'){
                    res++;
                    markIsland(grid, r, c);
                }
            }
        }

        return res;
    }
};
