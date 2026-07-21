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
        // return if the list is empty
		// seed the minHeap (check empty LL)
		// while minheap not empty pop push from the same LL if node exists

		if(lists.empty()) return nullptr;

		ListNode* dummy = new ListNode();

		auto cmp = [](ListNode* a, ListNode* b){
			return a->val>b->val;
		};

		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

		for(ListNode* node: lists) if(node) minHeap.push(node);

		ListNode* curr = dummy;
		while(!minHeap.empty()){
			ListNode* node = minHeap.top();
			minHeap.pop();
			curr->next = node;
			curr = curr->next;

			if(node->next) minHeap.push(node->next);
		}

		return dummy->next;
    }
};
