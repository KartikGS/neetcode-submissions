class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
		unordered_map<int, int> mp;
		int maxStart = -1;
		
		for(vector<int>& interval: intervals) {
			mp[interval[0]] = max(mp[interval[0]], interval[1]);
			maxStart = max(maxStart, interval[0]);
		}

		vector<vector<int>> res;
		int intervalStart = -1;
		int have = -1;
		
		for(int i =0; i<=maxStart; i++){
			if(mp.count(i)){
				if(intervalStart == -1) intervalStart = i;
				have = max(have, mp[i]);
			}
			if(have == i){
				res.push_back({intervalStart, have});
				intervalStart = -1;
				have = -1;
			}
		}
		if(have != -1){
			res.push_back({intervalStart, have});
		}

		return res;
    }
};
