class Solution {
    unordered_map<int, vector<int>> preqMap;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++) preqMap[i] = {};
        
        for(auto i: prerequisites) preqMap[i[0]].push_back(i[1]);

        for(int i=0;i<numCourses;i++){
            if(!dfs(i)) return false; 
        }

        return true;
    }

    bool dfs(int course){
        if(preqMap[course].empty()) return true;
        
        if(visiting.count(course)) return false;

        visiting.insert(course);
        for(auto i: preqMap[course]){
            if(!dfs(i)) return false;
        }
        visiting.erase(course);
        preqMap[course].clear();

        return true;
    }
};
