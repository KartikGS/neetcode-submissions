class DSU {
	vector<int> Parent, Size;
	int components;
	
	public:
	DSU(int n){
		components = n;
		Parent.resize(n);
		for(int i = 0; i<n; i++) Parent[i] = i;
		Size.resize(n, 1);
	}

	int find(int node){
		if(node == Parent[node]) return node;
		return Parent[node] = find(Parent[node]);
	}

	bool unionBySize(int u, int v){
		int pu = find(u);
		int pv = find(v);
		
		if(pu == pv) return false;
		components--;
		
		if(Size[pu]>=Size[pv]){
			Parent[pv] = Parent[pu];
			Size[pu] += Size[pv];
		} else {
			Parent[pu] = Parent[pv];
			Size[pv] += Size[pu];
		}

		return true;
	}

	int numOfComponents(){
		return components;
	}
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
		DSU dsu(n);
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(isConnected[i][j]) dsu.unionBySize(i, j);
			}
		}
		return dsu.numOfComponents();
    }
};