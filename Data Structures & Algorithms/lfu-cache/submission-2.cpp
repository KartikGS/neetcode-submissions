class Node {
   public:
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;
    Node(int k, int v, int c) : key(k), val(v), cnt(c), next(nullptr), prev(nullptr) {}
};

class LFUNode {
   public:
    Node* start;
    Node* end;
    int size;
    LFUNode* next;
    LFUNode* prev;
    LFUNode() {
        start = new Node(0, 0, 0);
        end = new Node(0, 0, 0);
        start->next = end;
        end->prev = start;
        size = 0;
    }
    void add(Node* node) {
        node->next = end;
        node->prev = end->prev;
        end->prev->next = node;
        end->prev = node;
        size++;
    }
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        size--;
    }
};

class LFUCache {
    LFUNode* start;
    LFUNode* end;
    int cap;
    int cnt;
    unordered_map<int, Node*> nodeMap;
    unordered_map<int, LFUNode*> cntMap;

   public:
    LFUCache(int capacity) {
        cap = capacity;
        cnt = 0;
        start = new LFUNode();
        end = new LFUNode();
        start->next = end;
        end->prev = start;
    }

    void add(LFUNode* tmp, LFUNode* add) {
        tmp->prev = add;
        tmp->next = add->next;
        add->next->prev = tmp;
        add->next = tmp;
    }

    void remove(LFUNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
    }

    int get(int key) {
        if (!nodeMap.count(key)) return -1;
        Node* node = nodeMap[key];
        LFUNode* cur = cntMap[node->cnt];
        cur->remove(node);
        if (cntMap.count(node->cnt + 1)) {
            LFUNode* tmp = cntMap[node->cnt + 1];
            tmp->add(node);
        } else {
            LFUNode* tmp = new LFUNode();
            cntMap[node->cnt + 1] = tmp;
            add(tmp, cur);
            tmp->add(node);
        }
        if (cur->size == 0) {
            remove(cur);
            cntMap.erase(node->cnt);
            delete cur;
        }
        node->cnt++;
        return node->val;
    }

    void put(int key, int value) {
        if (!nodeMap.count(key)) {
            if (cnt == cap) {
    LFUNode* lfu = start->next;        // least-frequent bucket
    Node* node = lfu->start->next;     // LRU node inside it
    lfu->remove(node);
    nodeMap.erase(node->key);
    if (lfu->size == 0) {
        remove(lfu);
        cntMap.erase(node->cnt);       // real frequency, not 1
        delete lfu;
    }
    delete node;
    cnt--;
}
            Node* node = new Node(key, value, 1);
            nodeMap[key] = node;
            if (cntMap.count(1)) {
                LFUNode* tmp = cntMap[1];
                tmp->add(node);
            } else {
                LFUNode* tmp = new LFUNode();
                cntMap[1] = tmp;
                add(tmp, start);
                tmp->add(node);
            }
            cnt++;
        } else {
            Node* node = nodeMap[key];
            LFUNode* cur = cntMap[node->cnt];
            cur->remove(node);
            if (cntMap.count(node->cnt + 1)) {
                LFUNode* tmp = cntMap[node->cnt + 1];
                tmp->add(node);
            } else {
                LFUNode* tmp = new LFUNode();
                cntMap[node->cnt + 1] = tmp;
                add(tmp, cur);
                tmp->add(node);
            }
            if (cur->size == 0) {
                remove(cur);
                cntMap.erase(node->cnt);
                delete cur;
            }
            node->cnt++;
            node->val = value;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
