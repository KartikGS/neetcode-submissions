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

        return divide(lists, 0, lists.size()-1);
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r){
        if(l>r) return nullptr;
        if(l==r) return lists[l];

        int m = l + (r-l)/2;
        ListNode* ln = divide(lists, l, m);
        ListNode* rn = divide(lists, m+1, r);

        return conquer(ln, rn);
    }

    ListNode* conquer(ListNode* l, ListNode* r){
        ListNode dummy;
        ListNode* curr = &dummy;

        while(l && r){
            if(l->val <= r->val){
                curr->next = l;
                l = l->next;
            } else {
                curr->next = r;
                r = r->next;
            }
            curr = curr->next;
        }
        if(l){
            curr->next = l;
        } else {
            curr->next = r;
        }

        return dummy.next;
    }
};
