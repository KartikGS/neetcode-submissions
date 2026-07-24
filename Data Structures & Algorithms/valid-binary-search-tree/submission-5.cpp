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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root,{INT_MIN, INT_MAX}});

        while(!q.empty()){
            auto curr = q.front();
            int val = curr.first->val;
            int lower = curr.second.first;
            int upper = curr.second.second;
            q.pop();
            if(val<=lower || val>=upper) return false;
            if(curr.first->left) q.push({curr.first->left, {lower, val}});
            if(curr.first->right) q.push({curr.first->right, {val, upper}});
        }

        return true;
    }
};
