class Solution {
    int solve(int node, int& count,vector<int>&vis,vector<vector<pair<int,int>>>&adjList){
        vis[node] =1;
        for(auto&[n,check]:adjList[node]){
            if(!vis[n]){
                count+=check;
                solve(n,count,vis,adjList);
            }
        }
        return 0;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adjList(n); // ai -> {bi,1/0} 1 means we need to reverse and 0 means no need
        for(auto& it:connections){
            int u = it[0], v = it[1];
            adjList[u].push_back({v,1});
            adjList[v].push_back({u,0});
        }
        int count =0;
        vector<int>vis(n);
        solve(0,count,vis,adjList);
        return count;
    }
};