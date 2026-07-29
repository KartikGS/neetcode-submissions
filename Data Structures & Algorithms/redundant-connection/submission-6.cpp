class DSU{
	public:
		vector<int> Parent, Size;

		DSU(int n){
			Parent.resize(n);
			Size.resize(n, 1);
			for(int i = 0; i<n; i++) Parent[i] = i;
		}

		int find(int node){
			if(node == Parent[node]) return node;
			return Parent[node] = find(Parent[node]);
		}

		bool unionBySize(int u, int v){
			int pu = find(u);
			int pv = find(v);

			if(pu == pv) return false;

			if(Size[pu]>=Size[pv]){
				Parent[pv] = Parent[pu];
				Size[pu]+=Size[pv];
			} else {
				Parent[pu] = Parent[pv];
				Size[pv]+=Size[pu];
			}

			return true;
		}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
		
		DSU dsu(n+1);

		for(int i = 0; i<n; i++){
			if(!dsu.unionBySize(edges[i][0], edges[i][1])) return edges[i];
		}

		return {};
    }
};
