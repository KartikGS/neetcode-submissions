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
    int maxSum = INT_MIN;

    int trackMaxSum(TreeNode* root){
        if(root==nullptr) return -1001;
        int maxL = trackMaxSum(root->left);
        int maxR = trackMaxSum(root->right);
        int maxLR= max(maxL, maxR);
        int sum = maxL + maxR + root->val;
        maxSum = max(maxSum,max(sum,maxLR));
        maxSum = max(maxSum, root->val);
        int sumLST = root->val+maxL;
        int sumRST = root->val+maxR;
        maxSum = max(maxSum, sumLST);
        maxSum = max(maxSum, sumRST);
        int maxLRST = max(sumLST,sumRST);
        if(maxLRST>root->val){
            return maxLRST;
        }
        return root->val;
    }

    int maxPathSum(TreeNode* root) {
        trackMaxSum(root);
        return maxSum;
    }
};
