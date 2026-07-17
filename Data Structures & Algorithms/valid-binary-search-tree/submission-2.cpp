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

using pbp = pair<bool,pair<int, int>>;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        pbp res = dfs(root);
        return res.first;
    }

    // return isBST, min, max
    pbp dfs(TreeNode* root){
        if(root==nullptr) return {true, {INT_MAX, INT_MIN}};

        pbp lst = dfs(root->left);
        pbp rst = dfs(root->right);

        if(!lst.first || !rst.first || lst.second.second>=root->val || rst.second.first<=root->val) return {false, {INT_MIN, INT_MAX}};
        
        int mi = lst.second.first==INT_MAX?root->val:lst.second.first;
        int ma = rst.second.second==INT_MIN?root->val:rst.second.second;
        
        return {true, {mi, ma}};
    }
};
