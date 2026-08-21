class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26);
        for(char task: tasks) freq[task-'A']++;

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];
        int numMax = 1;

        for(int i = 24; i>=0; i--){
            if(freq[i]==maxFreq){
                numMax++;
            } else {
                break;
            }
        }

        int time = (n+1)*(maxFreq-1)+numMax;
        
        return max((int)tasks.size(), time);
    }
};
