class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visiting;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i<numCourses; i++) adj[i] = {};

        for(auto preq: prerequisites) adj[preq[0]].push_back(preq[1]);

        for(int i = 0; i<numCourses; i++){
            if(!dfs(i)) return false;
        }

        return true; 
    }

    bool dfs(int crs){
        if(adj[crs].empty()) return true;

        if(visiting.find(crs) != visiting.end()) return false;

        visiting.insert(crs);
        for(auto i: adj[crs]){
            if(!dfs(i)) return false;
        }
        visiting.erase(crs);
        adj[crs].clear();

        return true;
    }
};
