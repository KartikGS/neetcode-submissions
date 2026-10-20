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
}

ListNode* reorder(ListNode* root, ListNode* cur){
	if(cur == nullptr) return root;
	ListNode* node = reorder(root, cur->next);
	if(!node) return nullptr;
	
if(node==cur || node->next == cur){
	cur->next = nullptr;
	return nullptr;
} else {
	ListNode* tmp = node->next;
	node->next = cur;
	cur->next = tmp;
	return tmp;
}
}
};



