class Solution {
    unordered_map<int, int> indegree;
    unordered_map<int, vector<int>> adj;
    vector<int> output;

    void dfs(int i){
        indegree[i]--;
        output.push_back(i);
        if(adj.count(i)){
            for(int crs: adj.at(i)){
                indegree[crs]--;
                if(indegree[crs]==0) dfs(crs);
            }
        }
        return;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.clear();
        indegree.clear();
        output.clear();
        for(const auto& preq: prerequisites){
            adj[preq[1]].push_back(preq[0]);
            indegree[preq[0]]++;
        }

        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0) dfs(i);
        }

        if(output.size()==numCourses) return output;
        return {};
    }
};
