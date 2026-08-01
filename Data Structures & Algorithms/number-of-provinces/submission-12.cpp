class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();//3
		int res = 0;

		for(int i = 0; i<n; i++){
			if(isConnected[i][i]==1){
				res++;//2
				queue<int> q;
				q.push(i);//2
				isConnected[i][i] = 0;

				while(!q.empty()){
					int city = q.front();//2
					q.pop();
					for(int nei = 0; nei<n; nei++){
						if(isConnected[city][nei] && isConnected[nei][nei]){
							q.push(nei);//1
							isConnected[nei][nei] = 0;
						}
					}
				}
			}
		}

		return res;
    }
};