class DSU{
	public:
		vector<int> Parent, Size;
		int components;

		DSU(int n){
			Parent.resize(n);
			Size.assign(n, 1);
			for(int i=0; i<n; i++) Parent[i] = i;
			components = n;
		}

		int find(int node){
			if(Parent[node] != node) Parent[node] = find(Parent[node]);
			return Parent[node];
		}

		bool unionSet(int u, int v){
			int pu = find(u);
			int pv = find(v);
			if(pv == pu) return false;

			components--;
			if(Size[pu]>=Size[pv]){
				Size[pu]+=Size[pv];
				Parent[pv] = pu;
			} else{
				Size[pv]+= Size[pu];
				Parent[pu] = pv;
			}
			return true;
		}

		int numOfComps(){
			return components;
		}
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
		DSU dsu = DSU(n);

		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(isConnected[i][j]) dsu.unionSet(i, j);
			}
		}

		return dsu.numOfComps();
    }
};