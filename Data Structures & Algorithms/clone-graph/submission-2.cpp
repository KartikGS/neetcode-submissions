/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> oldToNew;

        Node* start = new Node(node->val);
        oldToNew[node] = start;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(auto neighbor: curr->neighbors){
                if(oldToNew.count(neighbor)){
                    oldToNew[curr]->neighbors.push_back(oldToNew[neighbor]);
                } else {
                    Node* newNode = new Node(neighbor->val);
                    oldToNew[neighbor] = newNode;
                    q.push(neighbor);
                    oldToNew[curr]->neighbors.push_back(newNode);
                }
            }
        }

        return start;
    }
};
