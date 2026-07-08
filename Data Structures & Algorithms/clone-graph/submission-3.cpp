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
		oldToNew[node] = new Node(node->val);

		queue<Node*> q;
		q.push(node);

		while(!q.empty()){
			Node* curr = q.front();
			q.pop();

			for(auto n: curr->neighbors){
				if(!oldToNew.count(n)){
					oldToNew[n] = new Node(n->val);
					q.push(n);
				}
				oldToNew[curr]->neighbors.push_back(oldToNew[n]);
			}
		}
		return oldToNew[node];
    }
};
