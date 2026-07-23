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
        // 2
        // 2 10 4 8 6->null
        ListNode* curr = new ListNode();
        deque<ListNode*> dq;
        ListNode* temp = head;
        while(temp){
            dq.push_front(temp);
            temp = temp->next;
        }

        while(!dq.empty()){
            curr->next = dq.back();
            cout<<curr->next->val<<" ";
            curr = curr->next;
            dq.pop_back();

            if(dq.empty()) break;
            curr->next = dq.front();
            cout<<curr->next->val<<" ";
            curr = curr->next;
            dq.pop_front();
        }

        curr->next = nullptr;
    }
};
