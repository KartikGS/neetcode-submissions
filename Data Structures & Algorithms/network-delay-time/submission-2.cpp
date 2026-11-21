class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
unordered_map<int, vector<pair<int, int>>> adj;
for(const auto& time: times) adj[time[0]].emplace_back(time[1], time[2]);

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
minHeap.push({0, k});

set<int> visited;
int t = 0;
while(!minHeap.empty()){
	const auto cur = minHeap.top();
	minHeap.pop();
	int w1 = cur.first, n1 = cur.second;
	if(visited.count(n1)) continue;
	visited.insert(n1);
	t = w1;
	if(adj.count(n1)){
		for(const auto& next: adj[n1]){
	int n2 = next.first, w2 = next.second;
	if(!visited.count(n2)) minHeap.push({w1+w2, n2});
}
}
}

return visited.size()==n?t:-1;
}
};
