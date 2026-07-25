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
    int res;
    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);

        res = max(res, root->val+l+r);
        return root->val+max(l,r);
    }
};
