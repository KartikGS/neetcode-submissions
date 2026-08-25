class Twitter {
	int time;
	unordered_map<int, vector<pair<int, int>>> tweetMap;
	unordered_map<int, unordered_set<int>> followMap;
public:
    Twitter(): time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
		if(tweetMap[userId].size()>10) tweetMap[userId].erase(tweetMap[userId].begin());
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);
		auto cmp = [](vector<int>& a, vector<int>& b){
			return a[0]<b[0];
		};
		priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);

		for(int follow: followMap[userId]){
			if(tweetMap.count(follow)){
				int idx = tweetMap[follow].size()-1;
				maxHeap.push({-tweetMap[follow][idx].first, tweetMap[follow][idx].second, follow, idx});
				if(maxHeap.size()>10){
					maxHeap.pop();
				}
			}
		}

		priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap2(cmp);
		while(!maxHeap.empty()){
			vector<int> tmp = maxHeap.top();
			maxHeap.pop();
			maxHeap2.push({-tmp[0], tmp[1], tmp[2], tmp[3]});
		}		

		vector<int> res;

		while(!maxHeap2.empty() && res.size()!=10){
			vector<int> cur = maxHeap2.top();
			maxHeap2.pop();
			res.push_back(cur[1]);
			if(cur[3]>0){
				maxHeap2.push({tweetMap[cur[2]][cur[3]-1].first, tweetMap[cur[2]][cur[3]-1].second, cur[2], cur[3]-1});
			}
		}

		return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
