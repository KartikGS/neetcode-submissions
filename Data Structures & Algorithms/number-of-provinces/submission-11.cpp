class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		int res = 0;

		for(int i=0;i<n;i++){
			if(isConnected[i][i]==1){
				res++;
				dfs(isConnected, i, n);
			}
		}

		return res;    
    }

	void dfs(vector<vector<int>>& isConnected, int city, int n){
		if(isConnected[city][city]==0) return;

		isConnected[city][city] = 0;

		for(int i = 0; i<n; i++){
			if(isConnected[city][i] == 1) dfs(isConnected, i, n);
		}

		return;
	}
};