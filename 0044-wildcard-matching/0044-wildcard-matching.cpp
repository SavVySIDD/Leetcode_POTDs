class Solution {
    bool isAllStars(string &pattern, int i) {
        for (int j = 0; j <= i; j++) {
            if (pattern[j] != '*')
                return false;
        }
        return true;
    }

    bool solve(string &pattern, string &text,
               int i, int j,
               vector<vector<int>> &dp) {

        if (i < 0 && j < 0)
            return true;

        if (i < 0 && j >= 0)
            return false;

        if (j < 0 && i >= 0)
            return isAllStars(pattern, i);

        if (dp[i][j] != -1)
            return dp[i][j];

        if (pattern[i] == text[j] || pattern[i] == '?')
            return dp[i][j] =
                solve(pattern, text, i - 1, j - 1, dp);

        if (pattern[i] == '*')
            return dp[i][j] =
                solve(pattern, text, i - 1, j, dp) ||
                solve(pattern, text, i, j - 1, dp);

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(p, s, m - 1, n - 1, dp);
    }
};