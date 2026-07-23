class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> grid = isWater; //isWater is used as vis
        int n = grid.size(); int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> res(n,vector<int>(m));
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    res[i][j] = 0;
                }
            }
        }
        int drow[] = {0,-1,0,1};
        int dcol[] = {1,0,-1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow< n && ncol>=0 && ncol < m 
                && isWater[nrow][ncol]==0 ){
                    q.push({{nrow,ncol},dist+1});
                    isWater[nrow][ncol] =1;
                    res[nrow][ncol] = dist+1;
                }
            }
        }
        return res;
    }
};