class Solution {
public:
    unordered_map<int, vector<int>> dep;
    unordered_set<int> visiting;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i< numCourses; i++) dep[i] = {};

        for(auto preq: prerequisites) dep[preq[0]].push_back(preq[1]);

        for(int i=0; i<numCourses; i++){
            if(!dfs(i)) return false;
        }

        return true;
    }

    bool dfs(int crs){
        if(dep[crs].empty()) return true;
        if(visiting.find(crs)!=visiting.end()) return false;

        visiting.insert(crs);
        for(auto d: dep[crs]){
            if(!dfs(d)) return false;
        }
        visiting.erase(crs);
        dep[crs] = {};

        return true;
    }
};
