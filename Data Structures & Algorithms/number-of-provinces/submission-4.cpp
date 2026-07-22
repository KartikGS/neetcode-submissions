class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
		int res = 0;
		vector<bool> visited(n, false);
		queue<int> q;

		for(int i = 0; i<n; i++){
			if(!visited[i]){
				res++;
				q.push(i);
				visited[i] = true;
				while(!q.empty()){
					int city = q.front();
					q.pop();
					for(int j = 0; j<n; j++){
						if(isConnected[city][j] && !visited[j]){
							q.push(j);
							visited[j] = true;
						}
					}
				}
			}
		}

		return res;
    }
};