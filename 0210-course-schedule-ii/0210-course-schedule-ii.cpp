class Solution {
    void dfs(int node, vector<int>& vis, stack<int> &st, vector<vector<int>>& adj, vector<int>& visPath){
      vis[node] =1;
      visPath[node] =1;
      for(auto& it:adj[node]){
        if(!vis[it]) dfs(it,vis,st,adj,visPath);
        else if(visPath[it]) return;
      }
      visPath[node] =0;
      st.push(node);
  }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Your code here
        vector<vector<int>> adj(numCourses);
        for(auto& edge: prerequisites){
            int u = edge[0] ,v = edge[1];
            adj[v].push_back(u);
        }
        vector<int> vis(adj.size(),0), visPath(adj.size(),0);
        stack<int> st;
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(i,vis,st,adj,visPath);
            }
        }
        vector <int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        if (result.size() == numCourses) return result;
        else return {};
    }
};