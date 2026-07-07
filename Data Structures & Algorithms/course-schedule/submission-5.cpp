class Solution {
public:
	vector<vector<int>> adj;
	unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        	//courses 0 based
//create adj list
// detect cycle for each of these node
// if cycle detected return false
//no cycles return true
//cycle - perform dfs marking nodes visited
//in visited found return true
//else unmark visit and return false
if(numCourses == 0 ) return true;

adj.resize(numCourses, vector<int>(0));

for(auto i: prerequisites){
	adj[i[0]].push_back(i[1]);
}

for(int i = 0; i<numCourses; i++){
	if(!dfs(i)) return false; //dfs return false if a cycle is found
}

return true;
    }

	bool dfs(int crs){
	if(visiting.count(crs)) return false; //cycle found
	if(adj[crs].empty()) return true;
	
	visiting.insert(crs);
	for(auto i: adj[crs]){
		if(!dfs(i)) return false;
}
visiting.erase(crs);
adj[crs].clear();
return true;
}
};
