class Node {
	public:
		int tweetId;
		int timestamp;
		Node* prev;
		Node(int id, int time): tweetId(id), timestamp(time), prev(nullptr) {}
};

class Twitter {
	int counter=0;
	unordered_map<int, Node*> posts; //userId->Last Post Made
	unordered_map<int, unordered_set<int>> followers; //userId->set of userIds
	
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
	Node* node = new Node(tweetId, counter);
       	if(!posts.count(userId)){
		posts[userId] = node;
    	} else {
		node->prev = posts[userId];
		posts[userId] = node;
		
}
counter++;
    }
    
    vector<int> getNewsFeed(int userId) {
	auto cmp = [](Node* a, Node* b){
	return a->timestamp<b->timestamp;
};
        	priority_queue<Node*, vector<Node*>, decltype(cmp)> maxHeap(cmp);
	for(int follow: followers[userId]){
	if(posts.count(follow)) maxHeap.push(posts[follow]);
}
if(posts.count(userId)) maxHeap.push(posts[userId]);
vector<int> res;

while(!maxHeap.empty() && res.size()!=10){
	Node* node = maxHeap.top();
	maxHeap.pop();
	res.push_back(node->tweetId);
	if(node->prev) maxHeap.push(node->prev);
}

return res;
    }
    
    void follow(int followerId, int followeeId) {
        	followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        	followers[followerId].erase(followeeId);
    }
};


