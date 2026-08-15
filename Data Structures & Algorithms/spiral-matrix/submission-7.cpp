class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> num = {static_cast<int>(matrix[0].size()), static_cast<int>(matrix.size())-1};//0, 0
        vector<vector<int>> drc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int d = 0, r=0, c=-1;
        vector<int> res;

        while(num[d%2]){
            for(int i = 0; i<num[d%2]; i++){
                r+=drc[d][0];
                c+=drc[d][1];
                res.push_back(matrix[r][c]);
            }
            num[d%2]-=1;
            d = (d+1)%4;
        }

        return res;
    }
};
