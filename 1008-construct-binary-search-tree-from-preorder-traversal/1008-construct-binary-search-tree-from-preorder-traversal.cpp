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
    //bound is basically the root values as essentially the elements to the left of that can't be larger than that na.
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(i,preorder,INT_MAX);
    }
    TreeNode* solve(int& i, vector<int>&preorder, int bound){
        if(i==preorder.size() || preorder[i]>bound) return nullptr;
        TreeNode* temp = new TreeNode(preorder[i]);
        i++;//i is passed by reference as it has to increase for the whole preorder array properly
        temp->left = solve(i,preorder,temp->val);
        temp->right = solve(i,preorder,bound);
        return temp;
    }
};