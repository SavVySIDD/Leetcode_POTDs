class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // Put all boundary land cells into the queue
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]) {
                vis[i][m-1] = 1;
                q.push({i, m-1});
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !vis[0][j]) {
                vis[0][j] = 1;
                q.push({0, j});
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]) {
                vis[n-1][j] = 1;
                q.push({n-1, j});
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   !vis[nrow][ncol] &&
                   grid[nrow][ncol] == 1) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        // Remaining unvisited land cells are enclaves
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};