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
    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->left);
        if(left == -1) return -1;
        int right = solve(root->right);
        if(right == -1) return -1;
        if(abs(right-left) > 1) return -1;
        return 1+max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        int res = solve(root);
        return res==-1?false:true;
    }
};