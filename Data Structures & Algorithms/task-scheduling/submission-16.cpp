class Solution {
public:
    	int leastInterval(vector<char>& tasks, int n) {
        		
unordered_map<char, int> freq;
		for(char task: tasks) freq[task-'A']++;

		int maxFreq = 0;
		for(const pair<char, int>& item: freq) maxFreq = max(maxFreq, item.second);

		int idle = (maxFreq-1)*n;
		idle += maxFreq-1;//offset for below loop
		
		for(const pair<char, int>& item: freq) idle -= min(maxFreq-1, item.second);

		return tasks.size()+max(0, idle);
    	}
};
