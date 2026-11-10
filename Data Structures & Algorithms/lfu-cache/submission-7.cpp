class LFUCache {
	struct Node{
	int key;
	int val;	
	int cnt;
	Node* next;
	Node* prev;
	Node(int key, int val) : key(key), val(val), cnt(1), next(nullptr), prev(nullptr) {}
};

struct LinkedList{
	Node* start;
	Node* end;
	int size;
	LinkedList(){
	start = new Node(0,0);
	end = new Node(0,0);
	start->next = end;
	end->prev = start;
	size = 0;
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
	Node* node = start->next;
	start->next = start->next->next;
	node->next->prev = start;
	node->next = nullptr;
	node->prev = nullptr;
	size--;
	return node;
}
};

unordered_map<int, Node*> nodeMap;
unordered_map<int, LinkedList*> listMap;
int leastFreq;
int size;

void counter(Node* node){
	listMap[node->cnt]->remove(node);
	if(listMap[node->cnt]->size == 0 && leastFreq == node->cnt) leastFreq++;
node->cnt++;
if(!listMap.count(node->cnt)){
	listMap[node->cnt] = new LinkedList();
}
listMap[node->cnt]->pushRight(node);	
}
public:
LFUCache(int capacity): size(capacity) {}

~LFUCache(){
	for(pair<int, Node*> node: nodeMap) delete node.second;
	for(pair<int, LinkedList*> ll: listMap) delete ll.second;
}

int get(int key) {
	if(!nodeMap.count(key)) return -1;
	counter(nodeMap[key]);
	return nodeMap[key]->val;
}

void put(int key, int value) {
	if(nodeMap.count(key)){
	nodeMap[key]->val = value;
	counter(nodeMap[key]);
	return;
}
if(nodeMap.size() == size){
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
return;
}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

