class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	
vector<int> minTimes(n+1, INT_MAX);
	
	minTimes[0] = 0;
minTimes[k] = 0;
	
vector<vector<pair<int,int>>> adj(n+1);
	for(const vector<int>& time: times) adj[time[0]].push_back({time[1], time[2]});
	
queue<pair<int, int>> 	q;
q.push({k, 0});

while(!q.empty()){
	pair<int, int> cur = q.front();
	q.pop();
	for(pair<int, int> neighbor: adj[cur.first]){
	if(minTimes[neighbor.first]>cur.second+neighbor.second){
	minTimes[neighbor.first] = cur.second+neighbor.second;
	q.push({neighbor.first, minTimes[neighbor.first]});
}
}
}

int res = *max_element(minTimes.begin(), minTimes.end());
return res==INT_MAX?-1:res;
}
};

//minTimes = 0, 0, 1, 2, 3, 
//1->{2,1},{4,4},    2->{3,1},    3->{4,1}
//q->
