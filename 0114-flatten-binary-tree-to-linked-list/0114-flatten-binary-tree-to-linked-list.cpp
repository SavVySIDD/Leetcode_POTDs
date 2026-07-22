class Solution {
    void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        nodes.push_back(root);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }

public:
    void flatten(TreeNode* root) {
        if (!root) return;

        vector<TreeNode*> nodes;
        preorder(root, nodes);

        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
};