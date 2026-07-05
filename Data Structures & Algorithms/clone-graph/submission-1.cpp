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
    unordered_map<int, Node*> newNodes;
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        if(newNodes.count(node->val)) return newNodes[node->val];
        
        Node* curr = new Node(node->val, node->neighbors);
        newNodes.insert({curr->val, curr});
        
        vector<Node*> newNeighbors;
        for(auto i: curr->neighbors) newNeighbors.push_back(cloneGraph(i));
        curr->neighbors = newNeighbors;

        return curr;   
    }
};
