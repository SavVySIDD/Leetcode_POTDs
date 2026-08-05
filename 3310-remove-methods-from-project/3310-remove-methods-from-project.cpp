class Solution {
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node] =1;
        for(auto&it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto&it:invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v); //u invokes v
        }

        //vis[1] = suspicious, vis[0] = safe
        vector<int>vis(n,0);

        dfs(k,adj,vis); //marking all nodes visited from k
        vector<int>res;
        for(int i = 0; i < n; i++){
            if(!vis[i])
                res.push_back(i);
        }

        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];

            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        
        return res;
    }
};