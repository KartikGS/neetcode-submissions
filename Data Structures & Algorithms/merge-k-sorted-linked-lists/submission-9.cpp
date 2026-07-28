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

        while(lists.size()!=1){
            vector<ListNode*> mergedLists;

            for(int i = 0; i<lists.size(); i+=2){
                ListNode* left = lists[i];
                ListNode* right = (i+1==lists.size())?nullptr:lists[i+1];
                mergedLists.push_back(conquer(left, right));
            }

            lists = mergedLists;
        }
        return lists[0];
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
