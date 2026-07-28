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
        return divide(lists, 0, lists.size()-1);
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
        ListNode* cur = dummy;

        while(l && r){
            if(l->val<r->val){
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        if(l) cur->next = l;
        if(r) cur->next = r;

        return dummy->next;
    }
};
