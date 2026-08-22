class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); int m = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> res(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
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
                && mat[nrow][ncol]==1){
                    q.push({{nrow,ncol},dist+1});
                    mat[nrow][ncol] =0;
                    res[nrow][ncol] = dist+1;
                }
            }
        }
        return res;
    }
};