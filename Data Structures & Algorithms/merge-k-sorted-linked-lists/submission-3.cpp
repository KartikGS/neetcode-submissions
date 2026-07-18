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
        
        while(lists.size()>1){
            vector<ListNode*> mergedLists;
            for(int i = 0; i<lists.size(); i+=2){
                ListNode* l  =  lists[i];
                ListNode* r = i+1 < lists.size()?lists[i+1]:nullptr;
                mergedLists.push_back(conquer(l, r));
            }
            lists = mergedLists;
        }
        
        return lists[0];
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
