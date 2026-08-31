class Twitter {
	int time;
	unordered_map<int, vector<pair<int, int>>> posts;
	unordered_map<int, unordered_set<int>> follows;
public:
    	Twitter() {
		time = 0;
    	}
    
    	void postTweet(int userId, int tweetId) {
       		if(!posts.count(userId)){
	posts[userId] = {};
}
posts[userId].push_back({tweetId, time});
if(posts[userId].size()>10) posts[userId].erase(posts[userId].begin());
time++;
    	}
    
    	vector<int> getNewsFeed(int userId) {
       		priority_queue<vector<int>, vector<vector<int>>> maxHeapTmp;
		follows[userId].insert(userId);
for(int follower:follows[userId]){
	if(posts.count(follower)){
		pair<int, int> tmp = posts[follower].back();
		int idx = posts[follower].size()-1;
	maxHeapTmp.push({-tmp.second, tmp.first, follower, idx});
	if(maxHeapTmp.size()>10) maxHeapTmp.pop();
}
}

priority_queue<vector<int>, vector<vector<int>>> maxHeap;
while(!maxHeapTmp.empty()){
	vector<int> tmp = maxHeapTmp.top();
	maxHeapTmp.pop();
	maxHeap.push({-tmp[0], tmp[1], tmp[2], tmp[3]});
}

vector<int> feed;
while(!maxHeap.empty() && feed.size()!=10){
	vector<int> tmp = maxHeap.top();
	maxHeap.pop();
	feed.push_back(tmp[1]);
	if(tmp[3] !=0){
		pair<int, int> post = posts[tmp[2]][tmp[3]-1];
		maxHeap.push({post.second, post.first, tmp[2], tmp[3]-1});
}
}
return feed;
    	}
    
    	void follow(int followerId, int followeeId) {
        		follows[followerId].insert(followeeId);
    	}
    
    	void unfollow(int followerId, int followeeId) {
        		follows[followerId].erase(followeeId);
    	}
};


