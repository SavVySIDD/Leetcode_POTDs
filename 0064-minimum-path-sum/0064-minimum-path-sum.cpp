class Solution {
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& tr, int i, int j){
        if (i < 0 || j < 0) return 1e9;
        if (i == 0 && j == 0) return tr[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int dir1 = solve(tr,i,j-1);
        int dir2 =  solve(tr,i-1,j);
        return dp[i][j]= tr[i][j]+ min(dir1,dir2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(grid,n-1,m-1);
    }
};