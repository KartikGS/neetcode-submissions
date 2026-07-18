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
    int cnt;
    int res;
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        res = 0;
        inorder(root, k);
        return res;
    }

    void inorder(TreeNode* root, int k){
        if(!root) return;

        inorder(root->left, k);
        cnt++;
        if(cnt==k){
            res = root->val;
            return;
        }
        inorder(root->right, k);

        return;
    }
};
