class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(char task: tasks) cnt[task-'A']++;

        priority_queue<int, vector<int>> heap;

        for(int c: cnt) if(c) heap.push(c);

        queue<pair<int, int>> q;

        int time = 0;

        while(!q.empty() || !heap.empty()){
            time++;
            if(heap.empty()){
                time = q.front().second;
            } else {
                int c = heap.top()-1;
                heap.pop();
                if(c) q.push({c, time+n});
            }

            if(!q.empty() && q.front().second == time){
               heap.push(q.front().first);
               q.pop();
            }
        }

        return time;
    }
};
