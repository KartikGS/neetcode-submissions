class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    void remove(Node* curr){
        Node* nxt = curr->next;
        Node* prv = curr->prev;
        nxt->prev = prv;
        prv->next = nxt;
    }

    void insert(Node* curr){
        Node* prv = right->prev;
        prv->next = curr;
        curr->prev = prv;
        curr->next = right;
        right->prev = curr;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            remove(curr);
            insert(curr);
            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
        }
        Node* curr = new Node(key, value);
        mp[key] = curr;
        insert(curr);
        if(mp.size()>cap){
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
