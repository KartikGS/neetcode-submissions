class Solution {
public:
	int uniquePaths(int m, int n) {
		if(n>m) swap(m, n);
        		long long res = 1;
		int tmp = 1;
for(int i = m+n-2; i>m-1; i--){
	res*=i;
	res/=tmp;
	tmp++;
}
return res;
    	}
};

