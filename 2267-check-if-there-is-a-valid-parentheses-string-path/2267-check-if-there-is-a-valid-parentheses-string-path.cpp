class Solution {
    bool solve(vector<vector<char>>& grid, int i, int j, int cnt, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m)
            return false;


        int curr = grid[i][j] == '(' ? 1 : -1;
        cnt += curr;

        if(cnt < 0)
            return false;

        if(dp[i][j][cnt] != -1)
            return dp[i][j][cnt];

        if(i == n-1 && j == m-1 && cnt == 0)
            return true;

        int down = solve(grid, i+1, j, cnt,dp);
        int right = solve(grid, i, j+1, cnt,dp);
        return dp[i][j][cnt] = down || right;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
    n, vector<vector<int>>(m, vector<int>(n + m + 1, -1))
    );
        return solve(grid, 0, 0, 0,dp);
    }
};