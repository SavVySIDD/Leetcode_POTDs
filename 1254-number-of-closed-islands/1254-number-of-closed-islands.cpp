class Solution {
    bool dfs(int x, int y, vector<vector<int>>&vis,vector<vector<int>>& grid){
        int n = grid.size(),m = grid[0].size();
        vis[x][y]=1;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        bool isClosed = true;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                isClosed = false;
                continue;
            }

            if (grid[nx][ny] == 0 && !vis[nx][ny]) {
                if (!dfs(nx, ny, vis, grid)) {
                    isClosed = false;
                }
            }
        }
        return isClosed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int regions = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    if(dfs(i,j,vis,grid)) regions++;
                }
            }
        }
        return regions;
    }
};