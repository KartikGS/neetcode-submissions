class Solution {
public:
	vector<vector<int>> memo;

int uniquePaths(int m, int n) {
	if(m<n) swap(m, n);

	long long res = 1, j=1;

	for(int i = m+n-2; i>m-1; i--){
	res*=i;
	res/=j;
	j++;
}

return res;
}
};
