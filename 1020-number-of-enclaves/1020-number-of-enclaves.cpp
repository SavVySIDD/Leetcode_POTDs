class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& board){
        vis[r][c] =1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        int n = board.size(), m = board[0].size();
        for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>0 && nrow < n-1 && ncol>0 && ncol <m-1 &&
                vis[nrow][ncol]!=1 && board[nrow][ncol]==1){
                    dfs(nrow,ncol,vis,board);
                }
            }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n;i++){ //start & end col
            if(vis[i][0]!=1 && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(vis[i][m-1]!=1 && grid[i][m-1]==1){
                dfs(i,m-1,vis,grid);
            }
        }

        for(int j=0;j<m;j++){ //start and end row
            if(vis[0][j]!=1 && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
            if(vis[n-1][j]!=1 && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid);
            }
        }
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};