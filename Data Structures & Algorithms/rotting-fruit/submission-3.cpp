class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
		queue<pair<int,int>> q;
		int time = 0;

		for(int r = 0; r<grid.size(); r++){
			for(int c = 0; c< grid[0].size(); c++){
				if(grid[r][c]==1) fresh++;
				if(grid[r][c]==2) q.push({r, c});
			}
		}

		vector<pair<int, int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

		while(!q.empty() && fresh>0){
			int len = q.size();
			time++;
			for(int i = 0; i<len; i++){
				pair<int, int> curr = q.front();
				q.pop();

				for(auto drc: directions){
					int r = curr.first+drc.first;
					int c = curr.second+drc.second;
					if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1){
						grid[r][c] = 2;
						fresh--;
						q.push({r,c});
					}
				}
			}
		}

		return fresh==0?time:-1;
    }
};
