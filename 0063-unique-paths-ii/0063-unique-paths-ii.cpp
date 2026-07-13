class Solution {
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& tr, int i, int j){
        if (i < 0 || j < 0) return 0;
        if (tr[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]= solve(tr,i,j-1)+solve(tr,i-1,j);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(obstacleGrid,n-1,m-1);
    }
};