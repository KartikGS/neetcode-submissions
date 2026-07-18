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
    int mps = INT_MIN; //max path sum

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mps;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        mps = max({mps, left+right+root->val, root->val, root->val+left, root->val+right});

        return max({root->val, root->val+left, root->val+right});
    }
};
