class Node{
	public:
		int val;
		int key;
		Node* next;
		Node* prev;
};

class LRUCache {
	int cap;
	unordered_map<int, Node*> mp;
	Node* start;
	Node* end;
public:
    LRUCache(int capacity) {
    	cap = capacity;
	start = new Node();
	end = new Node();
	start->next = end;
	end->prev = start;
    }

    void remove(Node* node){
    	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->prev = nullptr;
	node->next = nullptr;
    }	

    void add(Node* node){
	end->prev->next = node;
	node->prev = end->prev;
	end->prev = node;
	node->next = end;
    }
    
    int get(int key) {
        	if(!mp.count(key)) return -1;
	Node* node = mp[key];
	remove(node);
	add(node);
	return node->val;
    }
    
    void put(int key, int value) {
if(mp.count(key)){
	Node* node = mp[key];
	node->val = value;
	remove(node);
	add(node);
} else {
	Node* node = new Node();
	node->val = value;
	node->key = key;
	add(node);
	mp[key] = node;
}

if(mp.size() > cap){
	mp.erase(start->next->key);
	remove(start->next);
}
    }
};

//st - 1,10 - 2, 20- en
