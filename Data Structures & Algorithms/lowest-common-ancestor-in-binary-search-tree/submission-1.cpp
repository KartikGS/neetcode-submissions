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
	TreeNode* pg;
	TreeNode* qg;
	TreeNode* res;
    	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
pg = p;
qg = q;
dfs(root);
return res;        
    	}
	pair<bool, bool> dfs(TreeNode* root){
		if(!root) return {false, false};
		pair<bool, bool> lst = dfs(root->left);
		pair<bool, bool> rst = dfs(root->right);
		
		if((lst.first && lst.second) || (rst.first && rst.second)) return {true, true};
		if((lst.first && rst.second) || (lst.second && rst.first)){
	res = root;
	return {true, true};
}
if(root == pg) {
	if(lst.second || rst.second) res = root;
return {true, lst.second || rst.second};
}
if(root == qg) {
	if(lst.first || rst.first) res = root;
return {lst.first || rst.first, true};
}

return {lst.first || rst.first, lst.second || rst.second};
}
};



