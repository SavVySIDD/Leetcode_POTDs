class Solution {
public:
    int minChanges(string s) {
        int changes = 0;

        // Check each pair: (0, 1), (2, 3), ...
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }

        return changes;
    }
};