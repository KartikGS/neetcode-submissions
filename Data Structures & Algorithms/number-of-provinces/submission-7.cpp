class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        for(int i =0; i<n;i++){
            if(isConnected[i][i]){ 
                dfs(isConnected, i, n);
                res++;    
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& isConnected, int city, int n){
        if(!isConnected[city][city]) return;

        isConnected[city][city] = 0;

        for(int nei = 0; nei<n; nei++){
            if(isConnected[city][nei]  && isConnected[nei][nei]){
                dfs(isConnected, nei, n);
            }
        }

        return;
    }
};