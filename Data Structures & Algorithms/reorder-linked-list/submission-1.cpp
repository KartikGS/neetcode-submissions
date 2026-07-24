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
        if(!head || head->next==nullptr || head->next->next==nullptr) return;
        // 2 4 6 8
        // 2 4    8 6
        //2 8 4 6
        //2,4,6,8,10
        //2,4    10, 8, 6
        //2 10 4 8 
        //r 2 10 4 8 6
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* l = head;
        ListNode* r = prev;
        ListNode* dummy = new ListNode();

        while(l && r){
            dummy->next = l;
            l = l->next;
            dummy = dummy->next;
            dummy->next = r;
            r = r->next;
            dummy = dummy->next;
        }
        if(l) dummy->next = l;
        if(r) dummy->next = r;
    }
};
