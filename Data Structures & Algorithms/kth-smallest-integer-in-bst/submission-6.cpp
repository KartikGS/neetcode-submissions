/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while(!stk.empty() || curr){

            while(curr){
                stk.push(curr);
                curr = curr->left;
            }

            k--;
            if(k==0){
                return stk.top()->val;
            }

            curr = stk.top();
            stk.pop();

            while(!stk.empty() && !curr->right){
                k--;
                if(k==0){
                    return stk.top()->val;
                }
                curr = stk.top();
                stk.pop();
            }

            curr = curr->right;
        }
    }
};
