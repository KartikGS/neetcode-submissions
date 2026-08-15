class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int top = 0, bottom = matrix.size();
        int left = 0, right = matrix[0].size();

        vector<int> res;

        while(top<bottom && left<right){
            for(int i = left; i<right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;//1

            for(int i = top; i<bottom; i++){
                res.push_back(matrix[i][right-1]);
            }
            right--;//1
            
            if(!(top<bottom && left<right)) break;

            for(int i = right-1; i>=left; i--){
                res.push_back(matrix[bottom-1][i]);
            }
            bottom--;

            for(int i = bottom-1; i>=top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};
