class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        dist[0][0] = 0;
        while(!pq.empty()){
            auto [diff, rc] = pq.top();
            auto [row, col] = rc;
            pq.pop();
            if(row==n-1 && col ==m-1) return diff;

            for(int i=0;i<4;i++){
                int nx = row+dx[i];
                int ny = col+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int newEffort = max(abs(heights[nx][ny]-heights[row][col]), diff);
                    if(newEffort<dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};