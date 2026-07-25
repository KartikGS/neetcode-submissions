class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adj;
    unordered_set<int> cycle;
    int cycleStart;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n+1);

        for(vector<int> i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        visited.resize(n+1, false);
        cycle.clear();
        cycleStart = -1;

        dfs(1, -1);

        for(int i = n-1; i>=0; i--){
            int u = edges[i][0], v = edges[i][1];
            if(cycle.count(u) && cycle.count(v)) return {u, v};
        }

        return {};
    }

    bool dfs(int node, int parent){
        if(visited[node]) {
            cycle.insert(node);
            cycleStart = node;
            return true;
        }

        visited[node] = true;

        for(int nei: adj[node]){
            if(nei!=parent && dfs(nei, node)){
                if(cycleStart==node){
                    cycleStart=-1;
                } else if(cycleStart!=-1){
                    cycle.insert(node);
                }
                return true;
            }
        }

        return false;
    }
};
