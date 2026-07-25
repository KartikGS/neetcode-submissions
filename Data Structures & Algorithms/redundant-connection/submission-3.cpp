class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1);
        vector<int> rank(n+1, 1);

        for(int i = 0; i<=n; i++) par[i] = i;

        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            if(!Union(u, v, par, rank)) return {u, v};
        }

        return {};
    }
private:
    int Find(int node, vector<int>& par){
        int p = par[node];
        while(p!=par[p]){
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    int Union(int u, int v, vector<int>& par, vector<int>& rank){
        int pu = Find(u, par);
        int pv = Find(v, par);

        if(pu==pv) return false;

        if(rank[pu]>rank[pv]){
            par[pv] = par[pu];
            rank[pu]+=rank[pv];
        } else{
            par[pu] = par[pv];
            rank[pv]+=rank[pu];
        }
        return true;
    }
};
