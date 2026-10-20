class LFUCache {
struct Node {
	int key;
	int val;
	int cnt;
	Node* next;
	Node* prev;
	Node(int key, int val): key(key), val(val), cnt(1), next(nullptr), prev(nullptr) {}
};

struct LinkedList {
	Node* start;
	Node* end;
	int size;
	LinkedList(){
	start = new Node(0,0);
	end = new Node(0,0);
	size = 0;
	start->next = end;
	end->prev = start;
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
	Node* node = start->next;
	start->next = node->next;
	start->next->prev = start;
	size--;
	return node;
}
};

unordered_map<int, Node*> nodeMap;
unordered_map<int, LinkedList*> listMap;
int minCnt;
int size;

void counter(Node* node){
	LinkedList* ll = listMap[node->cnt];
	ll->remove(node);
	if(minCnt == node->cnt && ll->size==0){
	minCnt++;
}
node->cnt++;
if(!listMap.count(node->cnt)){
	listMap[node->cnt] = new LinkedList();
}
listMap[node->cnt]->pushRight(node);
}
public:
    	LFUCache(int capacity): size(capacity) {}
    
    	int get(int key) {
		if(!nodeMap.count(key)) return -1;
		Node* node = nodeMap[key];
		counter(node);
		return node->val;
    	}
    
    	void put(int key, int value) {
        		if(nodeMap.count(key)){
	Node* node = nodeMap[key];
	node->val = value;
	counter(node);
	return;
}
if(nodeMap.size() == size){
	Node* node = listMap[minCnt]->popLeft();
	nodeMap.erase(node->key);
	delete node;
}
Node* node = new Node(key, value);
nodeMap[key] = node;
minCnt = 1;
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


