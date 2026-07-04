class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); int m =image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int drow[] ={0,-1,0,1};
        int dcol[] ={1,0,-1,0};
        int iniColor = image[sr][sc];
        image[sr][sc] = color;
        if(iniColor == color) return image;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                image[nrow][ncol]==iniColor){
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};