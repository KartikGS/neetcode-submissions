class DSU{
    vector<int> Parent, Size;
    int numOfComp;

    public:

    DSU(int n){
        Parent.resize(n);
        Size.assign(n,1);
        for(int i=0; i<n; i++) Parent[i] = i;
        numOfComp = n; 
    }

    int find(int node){
        if(Parent[node] == node) return node;
        return Parent[node] = find(Parent[node]);
    }

    bool unionSize(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu==pv) return false;
        numOfComp = numOfComp-1;
        cout<<numOfComp;

        if(Size[pu]>=Size[pv]){
            Parent[pv] = pu;
            Size[pu]+= Size[pv];
        } else{
            Parent[pu] = pv;
            Size[pv]+=Size[pu];
        }
        return true;
    }

    int remComp(){
        return numOfComp;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU* dsu = new DSU(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]){ 
                    dsu->unionSize(i, j);
                }
            }
        }

        return dsu->remComp();
    }
};