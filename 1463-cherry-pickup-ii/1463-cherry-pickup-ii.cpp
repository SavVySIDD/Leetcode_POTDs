class Solution {
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid, int r, int c1, int c2){
        int n = grid.size(), m = grid[0].size();
        if(r==n) return 0;
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int cherry = grid[r][c1];
        if(c1!=c2){ // not on the same cell
            cherry+= grid[r][c2];
        }
        int ans = INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nr = r+1;
                int nc1 = c1 + i;
                int nc2 = c2 + j;

                if(nc1>=0 && nc1<m && nc2>=0 && nc2<m){
                    ans = max(ans, solve(grid,nr,nc1,nc2));
                }
            }
        }
        return dp[r][c1][c2]= cherry + ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,m-1);
    }
};