class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(1000, vector<int>(1000, 0));
        unordered_map<int, int> nop;//number of prerequisites
        
        for(auto i:prerequisites){
            g[i[0]][i[1]] = 1;
            nop[i[0]]++;
            if(nop[i[1]]==0) nop[i[1]]=0;
        }

        queue<int> q;
        for(auto it:nop){
            if(it.second==0) q.push(it.first);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 0;i<1000;i++){
                if(g[i][curr]==1){ 
                    nop[i]--;
                    if(nop[i]==0) q.push(i);
                }
            }
        }

        bool ans = true;

        for(auto it:nop){
            if(it.second!=0) {
                ans = false;
                break;
            }
        }

        return ans;
    }
};
