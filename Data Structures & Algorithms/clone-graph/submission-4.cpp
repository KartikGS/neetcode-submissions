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
    unordered_map<Node*, Node*> oldToNew;

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;

        if(oldToNew.find(node) != oldToNew.end()) return oldToNew[node];

        Node* clone = new Node(node->val);
        oldToNew[node] = clone;

        for(auto n: node->neighbors){
            Node* nClone = cloneGraph(n);
            clone->neighbors.push_back(nClone);
        }

        return clone;
    }
};
