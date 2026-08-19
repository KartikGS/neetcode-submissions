class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
		map<int, int> mp;
		
		for(vector<int>& interval: intervals) {
			mp[interval[0]]++;
			mp[interval[1]]--;
		}

		vector<vector<int>> res;
		vector<int> interval;
		int have = 0;
		
		for(pair<int,int> item: mp){
			if(interval.empty()){
				interval.push_back(item.first);
			}
			have+=item.second;
			if(have==0){
				interval.push_back(item.first);
				res.push_back(interval);
				interval.clear();
			}
		}
		return res;
    }
};
