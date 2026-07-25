class DSU{
    vector<int> Parent, Size;
    int components;
    
    public:
    DSU(int n){
        Parent.resize(n);
        for(int i=0; i<n; i++) Parent[i] = i;
        Size.resize(n, 1);
        components = n;
    }

    int find(int node){
        if(node == Parent[node]) return node;
        return Parent[node] = find(Parent[node]);
    }

    bool unionSize(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false;
        components = components - 1;

        if(Size[pu]>=Size[pv]){
            Parent[pv] = pu;
            Size[pu]+=Size[pv];
        } else {
            Parent[pu] = pv;
            Size[pv]+= Size[pu];
        }

        return true;
    }

    int numOfComp(){
        return components;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //edge where both the nodes have a degree of greater than  1
        int n = edges.size();
        for(int i=n-1; i>=0; i--){
            DSU dsu(n);
            for(int j=0;j<n;j++){
                if(j!=i) dsu.unionSize(edges[j][0]-1,edges[j][1]-1);
            }
            if(dsu.numOfComp()==1) return edges[i];
        }
        return edges[1];
    }
};
//5-6, 6-7