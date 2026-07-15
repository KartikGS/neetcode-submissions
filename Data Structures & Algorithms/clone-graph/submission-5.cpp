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
        if(node == nullptr) return node;

        unordered_map<Node*, Node*> oldToNew;

        queue<Node*> q;

        Node* clone = new Node(node->val);
        oldToNew[node] = clone;

        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(auto n: curr->neighbors){
                if(oldToNew.find(n) == oldToNew.end()){
                    Node* nClone = new Node(n->val);
                    oldToNew[n] = nClone;
                    q.push(n);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[n]);
            }

        }

        return clone;
    }
};
