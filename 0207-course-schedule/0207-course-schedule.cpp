class Solution {
    //This function essentially checks for cycle 
    //visPath tells who was the parent or from what path the current node is coming basically if the node is in the recusrions stack or not
    bool dfsCheck(int node,vector<int>& vis, vector<int>& visPath,vector<vector<int>>& adj ){
        vis[node] =1;
        visPath[node] =1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,vis,visPath,adj)) return true;
            }
            else if(visPath[it]) return true;
            // So essentially if visited and and in the recursion stack and again came across so cycle found
        }
        visPath[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& edge: prerequisites){
            int u = edge[0] ,v = edge[1];
            adj[v].push_back(u);
        }
        vector<int> vis(numCourses,0),visPath(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfsCheck(i,vis,visPath,adj)) return false;
                //So essentially this means if cycle found all courses can't be finished
            }
        }
        return true;
    }
};