class Solution {
    void dfs(vector<vector<int>>& adjList, vector<bool>&vis, int&v, int&e, int node){
        vis[node] = true;
        v++;
        e+= adjList[node].size();
        for(auto&it:adjList[node]){
            if(!vis[it]){
                dfs(adjList,vis,v,e,it);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count =0;
        vector<vector<int>> adjList(n);
        for(auto&it:edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            int v =0, e =0;
            dfs(adjList,vis,v,e,i);
            if(v*(v-1) == e){ // nC2 = v*(v-1)/2 == e/2 as the edges are counted twice
                count++;
            }
        }
        return count;
    }
};