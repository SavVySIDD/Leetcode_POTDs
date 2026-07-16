class Solution {

    class BSTIterator {

        stack<TreeNode*> st;
        bool reverse;

        void pushAll(TreeNode* root){

            while(root){

                st.push(root);

                if(reverse)
                    root = root->right;
                else
                    root = root->left;
            }
        }

    public:

        BSTIterator(TreeNode* root, bool rev){

            reverse = rev;
            pushAll(root);
        }

        int next(){

            TreeNode* temp = st.top();
            st.pop();

            if(reverse)
                pushAll(temp->left);
            else
                pushAll(temp->right);

            return temp->val;
        }

        bool hasNext(){

            return !st.empty();
        }
    };

public:

    bool findTarget(TreeNode* root, int k) {

        if(!root) return false;

        BSTIterator l(root, false); // gets the next element
        BSTIterator r(root, true); //gets the previous element

        int left = l.next();
        int right = r.next();

        while(left < right){

            int sum = left + right;

            if(sum == k)
                return true;

            else if(sum < k)
                left = l.next();

            else
                right = r.next();
        }

        return false;
    }
};