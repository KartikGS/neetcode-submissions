class Twitter {
	int time;
	unordered_map<int, vector<pair<int, int>>> tweetMap;
	unordered_map<int, unordered_set<int>> followMap;
public:
    Twitter(): time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
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
				maxHeap.push({tweetMap[follow][idx].first, tweetMap[follow][idx].second, follow, idx});
			}
		}

		vector<int> res;

		while(!maxHeap.empty() && res.size()!=10){
			vector<int> cur = maxHeap.top();
			maxHeap.pop();
			res.push_back(cur[1]);
			if(cur[3]>0){
				maxHeap.push({tweetMap[cur[2]][cur[3]-1].first, tweetMap[cur[2]][cur[3]-1].second, cur[2], cur[3]-1});
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
