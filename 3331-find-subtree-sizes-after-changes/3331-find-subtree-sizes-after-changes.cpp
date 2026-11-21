class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        // Build the original tree.
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        // closest[c] is the closest ancestor with character c.
        vector<int> closest(26, -1);

        // Initially, each node is the only node in its subtree.
        vector<int> answer(n, 1);

        // Events: {node, entering or exiting}.
        // true = entering, false = exiting.
        stack<pair<int, bool>> st;
        st.push({0, true});

        while (!st.empty()) {
            auto [node, entering] = st.top();
            st.pop();

            int c = s[node] - 'a';

            if (entering) {
                // Save the previous closest ancestor for this character.
                int previous = closest[c];

                // Store the final parent in a separate array.
                // If there is no matching ancestor, keep the original parent.
                if (previous != -1) {
                    parent[node] = previous;
                }

                closest[c] = node;

                // Restore closest[c] when this subtree is finished.
                st.push({node, false});

                for (int child : children[node]) {
                    st.push({child, true});
                }
            } else {
                // closest[c] is currently this node. Its final parent
                // is the previous matching ancestor, if one existed.
                if (parent[node] != -1 && s[parent[node]] == s[node]) {
                    closest[c] = parent[node];
                } else {
                    closest[c] = -1;
                }

                // Add this node's final subtree size to its final parent.
                if (parent[node] != -1) {
                    answer[parent[node]] += answer[node];
                }
            }
        }

        return answer;
    }
};