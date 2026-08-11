class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        int numTasks = tasks.size();//4

        priority_queue<int, vector<int>> maxHeap;

        unordered_map<int, int> freq;

        for(const char& task: tasks) freq[task-'A']++;

        for(const pair<int, int>& item: freq) maxHeap.push(item.second);

        unordered_map<int, int> cooldown;

        while(numTasks){
            res++;

            if(cooldown.count(res)) maxHeap.push(cooldown[res]);

            if(maxHeap.empty()) continue;

            numTasks--;
            if(maxHeap.top()!=1) cooldown[res+n+1] = maxHeap.top()-1;
            maxHeap.pop();
        }

        return res;
    }
};
