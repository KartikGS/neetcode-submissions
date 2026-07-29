class Solution {
public:
    	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        		//1 based index
		int n = edges.size();
		vector<vector<int>> adj(n+1);
		vector<int> indegree(n+1);
		
		for(const vector<int>& edge: edges){
			int v1 = edge[0], v2 = edge[1];
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
	indegree[v1]++;
	indegree[v2]++;
}

queue<int> q;
for(int i = 1; i<=n; i++){
	if(indegree[i] == 1) q.push(i);
}

while(!q.empty()){
	int node = q.front();
	q.pop();
	indegree[node]--;
	for(int nei: adj[node]){
	if(indegree[nei]>1){
	indegree[nei]--;
	if(indegree[nei] == 1) q.push(nei);
}
}
}

for(int i = n-1; i>=0; i--){
	int v1 = edges[i][0], v2 = edges[i][1];
	if(indegree[v1] == 2 && indegree[v2] == 2) return {v1, v2};
}

return {};
    	}
};
