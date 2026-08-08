class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = largest index j in word2 that still needs to be matched
        // after processing word1[i...]
        vector<int> suf(n + 1, m);

        int j = m - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(j >= 0 && word1[i] == word2[j])
                j--;
            suf[i] = j + 1;
        }

        vector<int> ans;
        bool used = false;

        int i = 0;
        j = 0;

        while(i < n && j < m) {

            // Normal match
            if(word1[i] == word2[j]) {
                ans.push_back(i);
                i++;
                j++;
            }
            // Use the one mismatch if it is still safe
            else if(!used && suf[i + 1] <= j + 1) {
                used = true;
                ans.push_back(i);
                i++;
                j++;
            }
            else {
                i++;
            }
        }

        if(j == m)
            return ans;

        return {};
    }
};