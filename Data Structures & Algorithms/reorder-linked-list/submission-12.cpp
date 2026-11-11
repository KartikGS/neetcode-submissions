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

ListNode* reorder(ListNode* root, ListNode* node){
	if(!node) return root;
	root  = reorder(root, node->next);
	if(!root) return nullptr;
	if(root==node || root->next == node){
	node->next = nullptr;
return nullptr;
}else{
	ListNode* tmp = root->next;
	root->next = node;
	node->next = tmp;
	return tmp;
}
}
};
