class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnts(26, 0);
        for(char task: tasks) cnts[task-'A']++;

        int maxf = *max_element(cnts.begin(), cnts.end());
        int maxCount = 0;

        for(int cnt: cnts) if(cnt == maxf) maxCount++;

        int time = (maxf-1)*(n+1) + maxCount;

        return max(int(tasks.size()), time);
    }
};
