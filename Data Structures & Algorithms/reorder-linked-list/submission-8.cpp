/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    	void reorderList(ListNode* head) {
        		reorder(head, head);
		return;
    	}
	
	ListNode* reorder(ListNode* root, ListNode* cur){
		if(!cur) return root;
		root = reorder(root, cur->next);
		if(!root) return nullptr;
		if(cur == root || root->next == cur){
	cur->next = nullptr;
return nullptr;
} else {
	ListNode* tmp = root->next;
	root->next = cur;
	cur->next = tmp;
	return tmp;
}
}
};

//1 2 33 4-2 5-1
//1-5-2-4-3
//1, 
