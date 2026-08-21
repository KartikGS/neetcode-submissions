class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> freq;
        for(char task: tasks) freq[task]++;

        priority_queue<int, vector<int>> maxHeap;

        for(pair<char, int> item: freq) maxHeap.push(item.second);

        queue<pair<int, int>> q;

        int res = 0;

        while(!maxHeap.empty() || !q.empty()){
            res++;
            if(maxHeap.empty()){
                res = q.front().first;
            } else {
                int cur = maxHeap.top()-1;
                maxHeap.pop();
                if(cur)q.push({res+n, cur});
            }

            if(!q.empty() && q.front().first == res){
                maxHeap.push(q.front().second);
                q.pop();
            }
        }

        return res;
    }
};
