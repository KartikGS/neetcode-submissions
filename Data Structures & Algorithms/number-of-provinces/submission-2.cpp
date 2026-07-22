class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
		int n = isConnected.size();
		vector<bool> visited(n, false);
		for(int i = 0; i<n; i++){
			if(!visited[i]){
				res++;
				dfs(i, isConnected, visited, n);
			}
		}
		return res;
    }

	void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited, int n){
		visited[city] = true;
		for(int nei = 0; nei<n; nei++){
			if(isConnected[city][nei] && !visited[nei]) dfs(nei, isConnected, visited, n);
		}
		return;
	}
};