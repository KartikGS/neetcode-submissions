class Solution {
   public:
   vector<pair<int,int>> drc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false)),
            atlantic(rows, vector<bool>(cols, false));
        queue<vector<int>> pacificQueue, atlanticQueue;
        for (int i = 0; i < rows; i++) {
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, cols-1});
        }
        for (int i = 0; i < cols; i++) {
            pacificQueue.push({0, i});
            atlanticQueue.push({rows-1, i});
        }
        bfs(atlanticQueue, atlantic, heights);
        bfs(pacificQueue, pacific, heights);

        vector<vector<int>> res;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout<<pacific[i][j]<<" "<<atlantic[i][j]<<"\n";
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }

    void bfs(queue<vector<int>> oceanQueue, vector<vector<bool>> &ocean, const vector<vector<int>>& heights) {
        while(!oceanQueue.empty()){
            vector<int> cur = oceanQueue.front();
            oceanQueue.pop();
            int r = cur[0], c = cur[1];
            ocean[r][c] = true;
            for(pair<int, int> d:drc){
                int nr = r+d.first, nc = c+d.second;
                if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && !ocean[nr][nc] && heights[nr][nc]>=heights[r][c]) oceanQueue.push({nr, nc});
            }
        }
    }
};
