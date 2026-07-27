class Solution {
public:
    	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        		//courses are 0 indexed
		//if not possible to finish all return empty array
		vector<int> res;
		int finish = 0;

		vector<vector<int>> adj(numCourses);
		vector<int> indegree(numCourses, 0);

		for(auto preq: prerequisites){
			adj[preq[1]].push_back(preq[0]);
			indegree[preq[0]]++;
}

queue<int> q;

for(int i=0; i<numCourses; i++){
	if(indegree[i]==0) q.push(i);
}

while(!q.empty()){
	int crs = q.front();
	q.pop();
	finish++;
	res.push_back(crs);
	for(int dep: adj[crs]){
	indegree[dep]--;
	if(indegree[dep]==0){
	q.push(dep);
}
}
}

		if(finish!=numCourses) res.clear();

        return res;
    	}
};


