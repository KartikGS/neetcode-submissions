class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        unordered_map<int, int> mp;
		int maxEnd = 0;

		for(vector<int>& interval: intervals){ 
			mp[interval[0]] = max(mp[interval[0]], interval[1]);
			maxEnd = max(maxEnd, interval[1]);
		}

		int startInterval = -1;
		int endInterval = -1;

		vector<vector<int>> res;

		for(int i = 0; i<=maxEnd; i++){
			if(mp.count(i)){
				if(startInterval == -1) startInterval = i;
				endInterval = max(endInterval, mp[i]);
			}
				if(i == endInterval){
					res.push_back({startInterval, i});
					startInterval = -1;
					endInterval = -1;
				}
		}

		return res;
    }
};
