class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size();
		int t = 0, b = matrix.size();
		vector<int> res;

		while(l<r && t<b){
			for(int i = l; i<r; i++){
				res.push_back(matrix[t][i]);
			}
			t++;
			for(int i = t; i<b; i++){
				res.push_back(matrix[i][r-1]);
			}
			r--;
			if(!(l<r && t<b)) break;
			for(int i = r-1; i>=l; i--){
				res.push_back(matrix[b-1][i]);
			}
			b--;
			for(int i = b-1; i>=t; i--){
				res.push_back(matrix[i][l]);
			}
			l++;
		}

		return res;
    }
};
