class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //if the grid is completely empty 0
        int fresh = 0;
        int minutes = -1;

        queue<pair<int, int>> q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        vector<pair<int,int>> directions = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

        q.push({-1,-1});
        while(!q.empty()){
            pair<int,int> cell = q.front();
            q.pop();
            
            if(cell.first ==-1){
                minutes++;
                if(!q.empty()) q.push({-1,-1});
                continue;
            }

            for(auto drc: directions){
                int row = cell.first+drc.first;
                int col = cell.second+drc.second;

                if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]==1){
                    grid[row][col]=2;
                    q.push({row,col});
                    fresh--;
                }
            }
        }

        return fresh==0?minutes:-1;
    }
};
