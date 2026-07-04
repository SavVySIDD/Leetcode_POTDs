class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[r][c] =1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        int n = board.size(), m = board[0].size();

        for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>0 && nrow < n-1 && ncol>0 && ncol <m-1 &&
                vis[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
                    dfs(nrow,ncol,vis,board);
                }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n =board.size(), m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n;i++){ //start & end col
            if(vis[i][0]!=1 && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(vis[i][m-1]!=1 && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }

        for(int j=0;j<m;j++){ //start & end row
            if(vis[0][j]!=1 && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            if(vis[n-1][j]!=1 && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};