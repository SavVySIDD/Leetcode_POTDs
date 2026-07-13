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
    int solve(TreeNode* root,int& res){
        if(!root) return 0;
        int left = max(0, solve(root->left, res)); //we take max with 0 as if it gives negative we can't just ignore those branches
        int right = max(0, solve(root->right, res));
        res = max(res, root->val + left + right);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        if(!root) return 0;
        solve(root,res);
        return res;
    }
};