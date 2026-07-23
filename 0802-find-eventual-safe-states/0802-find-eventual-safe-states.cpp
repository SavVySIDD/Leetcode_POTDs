class Solution {
    //cycle detection code
    bool dfs(vector<vector<int>>& graph,int node, vector<int>& vis,vector<int>&visPath){
        vis[node] = 1;
        visPath[node] = 1;
        for(auto& it:graph[node]){
            if(!vis[it] && dfs(graph,it,vis,visPath))return true;
            else if(visPath[it]) return true;
        }
        visPath[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int>res,vis(n,0),visPath(n,0);

        for(int i=0;i<n;i++){
            dfs(graph,i,vis,visPath);
        }
        for(int i =0;i<n;i++) if(visPath[i]==0) res.push_back(i);
        return res;
    }
};