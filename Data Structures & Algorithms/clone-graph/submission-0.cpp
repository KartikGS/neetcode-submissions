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
        if(node==nullptr) return nullptr;
        Node* start = new Node(node->val, node->neighbors);
        queue<Node*> q;
        unordered_map<int, Node*> valToNode;
        q.push(start);
        valToNode.insert({start->val, start});
        while(!q.empty()){
            Node * curr = q.front();
            q.pop();
            vector<Node*> nei;
            for(auto oldNei:curr->neighbors){
                if(valToNode.count(oldNei->val)){
                    nei.push_back(valToNode[oldNei->val]);
                }
                else{
                    Node* newNei = new Node(oldNei->val, oldNei->neighbors);
                    nei.push_back(newNei);
                    q.push(newNei);
                    valToNode.insert({newNei->val, newNei});
                }
            }
            curr->neighbors = nei;
        }
        return start;
    }
};

// 1-2, 1-3, 