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
    ListNode* newHead;
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        ListNode* tail = reverse(head);
        tail->next = nullptr;
        
        return newHead;
    }
    ListNode* reverse(ListNode* node){
        if(!node->next) {
            newHead = node;
            return node;
        }
        ListNode* tail = reverse(node->next);
        tail->next = node;
        return node;
    }
};
