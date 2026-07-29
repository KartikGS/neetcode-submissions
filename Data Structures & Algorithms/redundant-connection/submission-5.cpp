class Solution {
public:
	vector<vector<int>> adj;
	vector<bool> cycle;
	vector<bool> visiting;
	int cycleStart;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
		
		adj.resize(n+1);
		cycle.resize(n+1, false);
		visiting.resize(n+1, false);
		cycleStart = -1;

		for(const vector<int>& edge: edges) {
			int v1 = edge[0], v2 = edge[1];
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}

		dfs(1, -1);

		for(int i = n-1; i>=0; i--){
			int v1 = edges[i][0], v2 = edges[i][1];
			if(cycle[v1] && cycle[v2]) return {v1, v2};
		}

		return {};
    }

	bool dfs(int node, int parent){
		if(visiting[node]){
			cycleStart = node;
			return true;
		}

		visiting[node] = true;

		for(int nei: adj[node]){
			if(nei != parent){
				if(dfs(nei, node) && cycleStart != -1){
					cycle[node] = true;
					if(cycleStart == node) cycleStart = -1;
					return true;
				}
			}
		}

		visiting[node] = false;
		return false;
	}
};
