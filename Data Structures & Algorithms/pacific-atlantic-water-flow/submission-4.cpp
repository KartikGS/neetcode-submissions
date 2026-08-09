class Solution {
public:

	vector<pair<int, int>> drc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
		int rows = heights.size(), cols = heights[0].size();

		queue<pair<int,int>> pq;
		queue<pair<int,int>> aq;

		for(int i =0; i<rows; i++){
			pq.push({i, 0});
			aq.push({i, cols-1});
		}

		for(int i = 0; i<cols; i++){
			pq.push({0, i});
			aq.push({rows-1, i});
		}

		vector<vector<bool>> p(rows, vector<bool>(cols, false));
		vector<vector<bool>> a(rows, vector<bool>(cols, false));

		bfs(pq, p, heights);
		bfs(aq, a, heights);

		vector<vector<int>> res;

		for(int i = 0; i<rows; i++){
			for(int j = 0; j<cols; j++){
				if(p[i][j] && a[i][j]) res.push_back({i, j});
			}
		}

		return res;
    }

	void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& o, const vector<vector<int>>& heights){
		while(!q.empty()){
			const pair<int, int> cur = q.front();
			q.pop();
			const int r = cur.first, c = cur.second;
			o[r][c] = true;
			for(const pair<int, int>& d: drc){
				const int nr = r+d.first, nc = c+d.second;
				if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && !o[nr][nc] && heights[nr][nc]>=heights[r][c]){
					q.push({nr, nc});
				}
			}
		}
	}
};
