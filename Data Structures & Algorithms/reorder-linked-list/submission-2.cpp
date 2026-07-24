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
        head = rec(head, head->next);
    }

    ListNode* rec(ListNode* root, ListNode* curr){
        if(!curr){
            return root;
        }

        root = rec(root, curr->next);

        if(!root){
            return nullptr;
        }

        ListNode* tmp = nullptr;
        if(curr==root || root->next == curr){
            curr->next = nullptr;
        } else {
            tmp = root->next;
            root->next = curr;
            curr->next = tmp;
        }

        return tmp;
    }
};
