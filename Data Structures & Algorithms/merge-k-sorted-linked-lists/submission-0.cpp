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
        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i<lists.size(); i++) {
            if(lists[i]) pq.push({lists[i]->val, i});
        }

        while(!pq.empty()){
            pair<int, int> item = pq.top();
            int idx = item.second;
            pq.pop();

            if(!head){
                head = lists[idx];
                curr = lists[idx];
            } else {
                curr->next = lists[idx];
                curr = curr->next;
            }

            lists[idx] = lists[idx]->next;

            if(lists[idx]) pq.push({lists[idx]->val, idx});
        }

        return head;
    }
};
