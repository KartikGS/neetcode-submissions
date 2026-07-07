class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //there can be 0 prerequisites
        vector<vector<int>> adj(numCourses);
        unordered_map<int, int> indegree;

        for(auto preq: prerequisites){
            adj[preq[1]].push_back(preq[0]);
            indegree[preq[0]]++;
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }

        int coursesTaken = 0;
        while(!q.empty()){
            int curCrs = q.front();
            q.pop();
            coursesTaken++;
            for(auto dep: adj[curCrs]){
                indegree[dep]--;
                if(indegree[dep]==0) q.push(dep);
            }
        }

        return coursesTaken == numCourses;
    }
};
