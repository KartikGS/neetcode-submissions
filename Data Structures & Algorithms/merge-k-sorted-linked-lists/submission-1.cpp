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
        if(lists.empty()) return nullptr;
        ListNode dummy;
        ListNode* curr = &dummy;

        auto cmp = [](ListNode* a, ListNode* b){
            return a->val>b->val;
        };       
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for(ListNode* item: lists) if(item) minHeap.push(item);

        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();
            
            curr->next = node;
            curr = curr->next;
            
            node=node->next;
            if(node) minHeap.push(node);
        }

        return dummy.next;
    }
};
