class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res=0;
        vector<bool> visited(n, false);
        queue<int> q;

        for(int i =0; i<n; i++){
            
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                res++;
            }

            while(!q.empty()){
                int city = q.front();
                q.pop();
                for(int nei = 0; nei<n; nei++){
                    if(isConnected[city][nei] && !visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }

        return res;
    }
};