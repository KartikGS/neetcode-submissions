class LFUCache {
	struct Node{
	int key;
	int val;
	int cnt;
	Node* next;
	Node* prev;
	Node(int key, int val): key(key), val(val), cnt(1), next(nullptr), prev(nullptr) {}
};

struct LinkedList{
	Node* start;
	Node* end;
	int size;
	
	LinkedList(){
	size = 0;
	start = new Node(0, 0);
	end = new Node(0, 0);
	start->next = end;
	end->prev = start;
}

~LinkedList(){
	delete start;
	delete end;
}

void remove(Node* node){
	Node* next = node->next;
	Node* prev = node->prev;
	next->prev = prev;
	prev->next = next;
	node->next = nullptr;
	node->prev = nullptr;
	size--;
}

void pushRight(Node* node){
	Node* prev = end->prev;
	prev->next = node;
	node->prev = prev;
	end->prev = node;
	node->next = end;
	size++;
}

Node* popLeft(){
	Node* left = start->next;
	remove(start->next);
	return left;
}
};

unordered_map<int, Node*> nodeMap;
unordered_map<int, LinkedList*> listMap;
int capacity;
int leastFreq;

void counter(Node* node){
	listMap[node->cnt]->remove(node);
	if(listMap[node->cnt]->size ==0 && leastFreq == node->cnt){
	leastFreq++;
}
node->cnt++;
if(!listMap.count(node->cnt)){
	listMap[node->cnt] = new LinkedList();
}
listMap[node->cnt]->pushRight(node);
}
public:
    	LFUCache(int capacity): capacity(capacity), leastFreq(0) {}

	~LFUCache(){
	for(auto& item: listMap) delete item.second;
	for(auto& item: nodeMap) delete item.second;
}
    
    	int get(int key) {
        		if(!nodeMap.count(key)) return -1;
		Node* node = nodeMap[key];
		counter(node);
		return node->val;
    	}
    
    	void put(int key, int value) {
   	     	if(nodeMap.count(key)){
	Node* node = nodeMap[key];
	counter(node);
	node->val = value;
}
if(nodeMap.size() == capacity){
	Node* node = listMap[leastFreq]->popLeft();
	nodeMap.erase(node->key);
	delete node;
}
Node* node = new Node(key, value);
nodeMap[key] = node;
leastFreq = 1;
if(!listMap.count(1)){
	listMap[1] = new LinkedList();
}
listMap[1]->pushRight(node);
    	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

