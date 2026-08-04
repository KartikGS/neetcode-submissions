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
        vector<int> arr(2);
        arr[0] = k;
        inorder(root, arr);
        return arr[1];
    }

    void inorder(TreeNode* root, vector<int>& arr){
        if(!root) return;
        inorder(root->left, arr);
        if(arr[0]==0) return;
        arr[0]--;
        if(arr[0]==0){
            arr[1] = root->val;
            return;
        }
        inorder(root->right, arr);
    }
};
