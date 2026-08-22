class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
		int n = isConnected.size();
		queue<int> q;
		int res = 0;
		
		for(int i = 0; i<n; i++){
			if(isConnected[i][i]){
				res++;
				isConnected[i][i] = 0;
				q.push(i);
				while(!q.empty()){
					int cur = q.front();
					q.pop();
					for(int j = 0; j<n; j++){
						if(isConnected[cur][j] && isConnected[j][j]){
							isConnected[j][j] = 0;
							q.push(j);
						}
					}
				}
			}
		}

		return res;
    }
};