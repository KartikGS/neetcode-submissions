class Solution {
public:
    	vector<int> spiralOrder(vector<vector<int>>& matrix) {
        		
vector<int> res;
int rows = matrix.size(), cols = matrix[0].size();

vector<int> moves = {cols, rows-1};
vector<pair<int, int>> drc = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int d = 0, r = 0, c = -1;
while(moves[d%2]){
	for(int i = 0; i<moves[d%2]; i++){
		r+=drc[d].first;
		c+=drc[d].second;
		res.push_back(matrix[r][c]);
}
moves[d%2]--;
d = (d+1)%4;
}

return res;
    	}
};
