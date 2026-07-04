class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int freshCount =0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
                if(grid[i][j]==1)freshCount++;
            }
        }
        int dx[]= {1,-1,0,0};
        int dy[]= {0,0,-1,1};
        
        int res = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    while(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1){
                        grid[newX][newY]=2;
                        q.push({{newX,newY},t+1});
                        freshCount--;
                    }
                }
            }
            res = max(res,t);
        }
        
        return freshCount==0?res:-1;
    }
};