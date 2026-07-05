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
    void solve(map<int,vector<pair<int,int>>>& mp, TreeNode* root,int r, int c){
        if(!root) return;
        mp[c].push_back({r,root->val});
        solve(mp,root->left,r+1,c-1);
        solve(mp,root->right,r+1,c+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp; //col -> {row,val}
        solve(mp,root,0,0);
        vector<vector<int>> res;
        for(auto& it:mp){
            auto vec = it.second;
            sort(vec.begin(),vec.end());
            vector<int> col;
            for(auto& p:vec){
                col.push_back(p.second);
            }
            res.push_back(col);
        }
        return res;
    }
};