class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp; //key to node
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;    
    }

    void remove(Node* node){
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv;
    }

    void insert(Node* node){
        Node* currLast = right->prev;
        currLast->next = node;
        node->prev = currLast;
        node->next = right;
        right->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
        }
        Node* node = new Node(key, value);
        insert(node);
        mp[key] = node;

        if(mp.size()>cap){
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
        }
    }
};
