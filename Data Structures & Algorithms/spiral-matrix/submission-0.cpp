class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

		int t = 0;
		int l = 0;
		int b = matrix.size()-1;
		int r = matrix[0].size()-1;

		while(l<=r && t<=b){
			for(int i = l; i<=r; i++){
				res.push_back(matrix[t][i]);
			}
			t++;
			for(int i = t; i<=b; i++){
				res.push_back(matrix[i][r]);
			}
			r--;
			if(t<=b){
			for(int i = r; i>=l; i--){
				res.push_back(matrix[b][i]);
			}
			b--;
			}
			if(l<=r){
			for(int i = b; i>=t; i--){
				res.push_back(matrix[i][l]);
			}
			l++;
			}
			
		}

		return res;
    }
};

// l = 1
// t = 2
// r = 1
// b= 1

// [1,2,3,4],
// [5,6,7,8],
// [9,10,11,12]