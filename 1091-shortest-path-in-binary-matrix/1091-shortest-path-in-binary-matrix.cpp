class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m =grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        // vector<vector<int>>vis(n,vector<int>(m,0));
        int dx[]={1,-1,0,0,1,-1,1,-1};
        int dy[]={0,0,1,-1,1,-1,-1,1};
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0]=1; //marking as visited
        int res = INT_MAX;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if(x==n-1 && y==m-1) res = min(res,dist);
            for(int i=0;i<8;i++){
                int newX = x+dx[i];
                int newY = y+dy[i];
                if(newX<n && newX>=0 && newY<m && newY>=0 && grid[newX][newY]!=1){
                    grid[newX][newY] = 1;
                    q.push({{newX,newY},dist+1});
                }
            }
        }
        return res==INT_MAX ? -1:res;
    }
};