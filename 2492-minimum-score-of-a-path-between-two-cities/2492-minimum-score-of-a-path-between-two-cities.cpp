class Solution {
    int mini = INT_MAX;
    void dfs(vector<vector<pair<int,int>>>&adjList, int node,vector<int>&vis){
        vis[node]=1;
        for(auto&it:adjList[node]){
            int wt = it.second;
            mini = min(mini,wt);
            if(!vis[it.first]) dfs(adjList,it.first,vis);
        }
        return;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adjList(n+1);
        for(auto&it:roads){
            adjList[it[0]].push_back({it[1],it[2]});
            adjList[it[1]].push_back({it[0],it[2]});
        }
        vector<int> vis(n+1);
        dfs(adjList,1,vis);
        return mini;
    }
};