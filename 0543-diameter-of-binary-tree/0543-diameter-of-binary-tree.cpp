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
    int solve(TreeNode* root, int& maxDiam){
        if(!root)  return 0;
        int left = solve(root->left, maxDiam);
        int right = solve(root->right, maxDiam);
        maxDiam = max(maxDiam, left+right);
        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiam =0;
        solve(root,maxDiam);
        return maxDiam;
    }
};