class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;
        for(const auto& pair: prerequisites){
            prereq[pair[0]].push_back(pair[1]);
        }

        unordered_set<int> cycle;
        unordered_set<int> visited;

        vector<int> res;

        for(int i = 0; i<numCourses; i++){
            if(!dfs(i, prereq, cycle, visited, res)){
                return {};
            }
        }

        return res;
    }

    bool dfs(int i, unordered_map<int, vector<int>>& prereq, unordered_set<int>& cycle, unordered_set<int>& visited, vector<int>& res){
        if(cycle.count(i)) return false;
        if(visited.count(i)) return true;

        cycle.insert(i);
        if(prereq.count(i)){
        for(auto crs: prereq.at(i)){
            if(!dfs(crs, prereq, cycle, visited, res)){
                return false;
            }
        }
        }
        cycle.erase(i);
        visited.insert(i);
        res.push_back(i);

        return true;
    }
};
