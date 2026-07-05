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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res; 
        int level =0;
        if(!root) return res;
        while(!q.empty()){
            vector<int> nodelevel;
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                nodelevel.push_back(node->val);
            }
            if(level%2!=0) reverse(nodelevel.begin(),nodelevel.end());
            res.push_back(nodelevel);
            level++;
        }
        return res;
    }
};