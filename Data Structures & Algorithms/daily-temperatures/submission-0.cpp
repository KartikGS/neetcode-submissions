class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 30,38,30,36,35,40,28
		// 30 - 1
		// 38 - 
		int n = temperatures.size();
		vector<int> res(n, 0);

		stack<pair<int, int>> temp; // temp and idx

		for(int i = 0; i<n; i++){
			while(!temp.empty() && temp.top().first<temperatures[i]){
				pair<int, int> top = temp.top();
				temp.pop();
				res[top.second] = i-top.second;
			}
			temp.push({temperatures[i], i});
		}

		//idx = -1;
		//30 38 set day to 1 and incrment for every pop till i find a greater temp or stack is empty
		// 40 28

		return res;
    }
};
