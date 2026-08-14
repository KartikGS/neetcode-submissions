class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(const char& task:tasks) cnt[task-'A']++;

        int maxFreq = *max_element(cnt.begin(), cnt.end());
        int num = -1;//number of maxFreq

        for(int i = 0; i<26; i++) if(cnt[i]==maxFreq) num++;

        int idle = (maxFreq-1)*n+maxFreq-1;
        for(int i = 0;i<26; i++){
            idle-=min(maxFreq-1, cnt[i]);
        }

        return idle>0?(maxFreq+((maxFreq-1)*n)+num):tasks.size();
    }
};
//ABCABC
//4gaps- 2