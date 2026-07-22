class Solution {
public:
	unordered_set<int> visited;

    int findCircleNum(vector<vector<int>>& isConnected) {
        visited.clear();
		int res = 0;
		for(int i = 0;i<isConnected.size(); i++){
			if(visited.find(i) == visited.end()){
				res++;
				dfs(isConnected, i);
			}
		}
		return res;
    }

	void dfs(vector<vector<int>>& isConnected, int city){
		if(visited.find(city) != visited.end()) return;

		visited.insert(city);

		for(int i = 0;i<isConnected.size(); i++){
			if(isConnected[city][i] && i!=city) dfs(isConnected, i);
		}

		return;
	}
};