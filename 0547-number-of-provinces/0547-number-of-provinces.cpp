class Solution {
    void dfs(int node, vector<vector<int>>& adjList,vector<int>& vis){
        vis[node]=1;
        for(auto it: adjList[node]){
            if(!vis[it])
            dfs(it,adjList,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> vis(V,0);
        vector<vector<int>> adjList(V);
        int count=0;
        //adjacency matrix to adjacency list
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjList,vis);
            }
        }
        return count;
    }
};