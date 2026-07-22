class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
		int n = isConnected.size();
		for(int i = 0; i<n; i++){
			if(isConnected[i][i]){
				res++;
				dfs(i, isConnected, n);
			}
		}
		return res;
    }

	void dfs(int city, vector<vector<int>>& isConnected, int n){
		isConnected[city][city] = 0;
		for(int nei = 0; nei<n; nei++){
			if(isConnected[city][nei] && isConnected[nei][nei]) dfs(nei, isConnected, n);
		}
		return;
	}
};