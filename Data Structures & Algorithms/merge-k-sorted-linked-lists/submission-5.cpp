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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = divide(lists, 0, lists.size()-1);
		return res;
    }

	ListNode* divide(vector<ListNode*>& lists, int l, int r){
		if(l==r) return lists[l];
		if(l>r) return nullptr;

		int m = l+(r-l)/2;

		ListNode* left = divide(lists, l, m);
		ListNode* right = divide(lists, m+1, r);

		return conquer(left, right);
	}

	ListNode* conquer(ListNode* l, ListNode* r){
		ListNode* dummy = new ListNode();
		ListNode* curr = dummy;
		while(l && r){
			if(l->val<r->val){
				curr->next = l;
				l = l->next;
			} else {
				curr->next = r;
				r = r->next;
			}
			curr = curr->next;
		}
		if(l) curr->next = l;
		if(r) curr->next = r;

		return dummy->next;
	}
};
