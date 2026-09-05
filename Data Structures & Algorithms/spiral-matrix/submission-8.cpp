class Solution {
public:
    	vector<int> spiralOrder(vector<vector<int>>& matrix) {
        		vector<int> res;

spiral(0, -1, matrix.size(), matrix[0].size(), 0, 1, res, matrix);

		return res;
    	}

	void spiral(int r, int c, int rows, int cols, int dr, int dc, vector<int>& res, const vector<vector<int>>& matrix){
	if(rows == 0 || cols == 0) return;
	
	for(int i = 0; i<cols; i++){
	r+=dr;
	c+=dc;
	res.push_back(matrix[r][c]);
}

spiral(r, c, cols, rows-1, dc, -dr, res, matrix);
}
};