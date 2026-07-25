class Solution {
public:
    vector<bool> visited;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        visited.resize(n, false);
        int res = 0;
        for(int i =0; i<n;i++){
            if(!visited[i]){ 
                dfs(isConnected, i, n);
                res++;    
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& isConnected, int city, int n){
        if(visited[city]) return;

        visited[city] = true;

        for(int nei = 0; nei<n; nei++){
            if(isConnected[city][nei]  && !visited[nei]){
                dfs(isConnected, nei, n);
            }
        }

        return;
    }
};