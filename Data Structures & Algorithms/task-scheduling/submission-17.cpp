class Solution {
public:
    	int leastInterval(vector<char>& tasks, int n) {
        		
unordered_map<char, int> freq;
		for(char task: tasks) freq[task-'A']++;

		int maxFreq = 0;
		for(const pair<char, int>& item: freq) maxFreq = max(maxFreq, item.second);

		int maxCount = 0;
		for(const pair<char, int>& item: freq) if(item.second==maxFreq) maxCount++;

		int total = (n+1)*(maxFreq-1)+maxCount;

		return max(static_cast<int>(tasks.size()), total);
    	}
};
