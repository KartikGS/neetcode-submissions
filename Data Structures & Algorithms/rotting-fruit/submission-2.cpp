class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;
        
        for(int r=0;r<grid.size();r++){
            for(int c= 0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    fresh++;
                }
                if(grid[r][c]==2){
                    q.push({r,c});
                }
            }
        }

        vector<pair<int,int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty() && fresh>0){
            int len = q.size();
            
            for(int i = 0; i < len; i++){
                pair<int,int> cell = q.front();
                q.pop();
                
                for(auto drc: direction){
                    int r = cell.first+drc.first;
                    int c = cell.second + drc.second;
                    if(r>=0 && r<grid.size() && c >= 0 && c < grid[0].size() && grid[r][c]==1){
                        grid[r][c] = 2;
                        fresh--;
                        q.push({r,c});
                    }
                }

            }
            time++;
        }
        return fresh==0?time:-1;
    }
};
