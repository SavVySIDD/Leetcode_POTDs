class Solution {
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[r][c] =1;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};

        for(int i=0;i<4;i++){
            int nx = r+dx[i];
            int ny = c+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1' && !vis[nx][ny]){
                dfs(nx,ny,vis,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};