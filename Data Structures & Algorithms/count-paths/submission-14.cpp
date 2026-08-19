class Solution {
public:
    int uniquePaths(int m, int n) {
		if(m<n) swap(m, n);
        long long res = 1, j=1;
		for(int i = m; i<m+n-1; i++){
			res*=i;
			res/=j;
			j++;
		}
		return res;
    }
};

//20, 16
//1, 1
//20 34
//