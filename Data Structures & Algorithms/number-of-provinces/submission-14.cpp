class Solution {
public:
	vector<bool> visited;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
		visited.resize(n, false);
		int res = 0;

		for(int i = 0; i<n; i++){
			if(!visited[i]){
				res++;
				dfs(i, isConnected);
			}
		}

		return res;
    }

	void dfs(int i, const vector<vector<int>>& isConnected){
		if(visited[i]) return;

		visited[i] = true;

		for(int j=0; j<isConnected.size(); j++){
			if(isConnected[i][j] && !visited[j]) dfs(j, isConnected);
		}

		return;
	}
};