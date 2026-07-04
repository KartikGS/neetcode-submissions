class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) if(indegree[i]==0) q.push(i);

        int finish = 0;

        while(!q.empty()){
            int crs = q.front();
            q.pop();
            finish++;

            for(auto i: adj[crs]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }

        return finish == numCourses;
    }
};
