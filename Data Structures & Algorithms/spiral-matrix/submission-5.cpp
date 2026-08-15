class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        dfs(matrix.size()-1, matrix[0].size(), 0, -1, 0, 1, matrix, res);

        return res;
    }

    void dfs(int rows, int cols, int r, int c, int dr, int dc, vector<vector<int>>& matrix, vector<int>& res){
        if(cols == 0) return;

        for(int i = 0; i<cols; i++){
            r+=dr;
            c+=dc;
            res.push_back(matrix[r][c]);
        }

        dfs(cols-1, rows, r, c, dc, -dr, matrix, res);
    }
};