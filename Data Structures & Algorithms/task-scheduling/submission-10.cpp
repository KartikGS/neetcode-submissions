class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(const char& task:tasks) cnt[task-'A']++;

        priority_queue<int, vector<int>> maxHeap;
        for(int i = 0; i<26; i++) if(cnt[i]!=0) maxHeap.push(cnt[i]);

        queue<pair<int,int>> q;

        int res=0;

        while(!maxHeap.empty() || !q.empty()){
            res++;
            if(maxHeap.empty()){
                res = q.front().first;
            } else {
                int freq = maxHeap.top()-1;
                maxHeap.pop();
                if(freq) q.push({res+n, freq});
            }
            if(res==q.front().first){
                maxHeap.push(q.front().second);
                q.pop();
            }
        }

        return res;
    }
};
//4,1