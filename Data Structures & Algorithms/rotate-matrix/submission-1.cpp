class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //i, j first to j, n-i
		//0, 0 - 0, 2
		//0, 1 - 1, 2
		//0, 2 - 2, 2

		// i, j first to j, n-1-i
		//0, 0 - 0, 1- starting
		//tmp 1 - 2
		// 1, 1
		//nxn places
		//first layer from 0 to (n-1)/2
		// from 1 to (n-1)/2
		//above two step from 0 to n-1/2

		int n = matrix.size();
		int end = (n-1)/2;

		for(int i = 0; i<=end; i++){
			for(int j = i; j<=n-2-i; j++){
				int ni = j;
				int nj = n-1-i;
				int rep = matrix[i][j];
				cout<<ni<<" "<<nj<<"\n";
				while(ni!=i || nj!=j){
					int tmp = matrix[ni][nj];
					matrix[ni][nj] = rep;
					rep = tmp;
					int tni = ni;
					ni = nj;
					nj = n-1-tni;
				}
				matrix[i][j] = rep;
			}
		}
    }
};
//n = 3
//end = 1;
//i = 1, j = 1;
//ni = 1; nj = 1;
//rep = 2
//tmp = 4
//tni = 1, ni = 1,nj0 