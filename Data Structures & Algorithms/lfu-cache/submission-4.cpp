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
        int size;
        Node* start;
        Node* end;
        LinkedList(){
            size = 0;
            start = new Node(0,0);
            end = new Node(0,0);
            start->next = end;
            end->prev = start;
        }
        ~LinkedList(){
            delete start;
            delete end;
        }

        void pushEnd(Node* node){
            Node* last = end->prev;
            last->next = node;
            node->prev = last;
            node->next = end;
            end->prev = node;
            size++;
        }

        void remove(Node* node){
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;
            node->next = nullptr;
            node->prev = nullptr;
            size--;
        }

        Node* removeFirst(){
            Node* first = start->next;
            remove(start->next);
            return first;
        }
    };

    int lfuCount;
    int capacity;
    unordered_map<int, Node*> nodeMap;
    unordered_map<int, LinkedList*> listMap;

    void counter(Node* node){
        LinkedList* ll = listMap[node->cnt];
        ll->remove(node);
        if(ll->size == 0 && lfuCount == node->cnt) lfuCount++;
        node->cnt++;
        if(!listMap.count(node->cnt)){
            listMap[node->cnt] = new LinkedList();
        }
        listMap[node->cnt]->pushEnd(node);
    }

public:

    LFUCache(int capacity): lfuCount(0), capacity(capacity) {}

    ~LFUCache(){
        for(auto& item: nodeMap) delete item.second;
        for(auto& item: listMap) delete item.second;
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
            return;
        }
        if(nodeMap.size()==capacity){
            LinkedList* ll = listMap[lfuCount];
            Node* node = ll->removeFirst();
            nodeMap.erase(node->key);
            delete node;
        }
        Node* node = new Node(key, value);
        nodeMap[key] = node;
        if(!listMap.count(1)){
            listMap[1] = new LinkedList();
        }
        listMap[1]->pushEnd(node);
        lfuCount = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */