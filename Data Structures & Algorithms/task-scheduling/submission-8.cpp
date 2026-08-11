class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnts(26, 0);
        for(char task: tasks) cnts[task-'A']++;

        sort(cnts.begin(), cnts.end());
        int maxf = cnts[25];
        int idle = (maxf-1)*n;

        for(int i = 24; i>=0; i--) idle-=min(cnts[i], maxf-1);

        return max(idle, 0)+tasks.size();
    }
};
