class Solution {
    bool checkCycle(vector<vector<int>>&adjList,vector<int>&vis,vector<int>&visPath, int node){
        vis[node] =1;
        visPath[node] =1;
        for(auto&it:adjList[node]){
            if(!vis[it]){
                if(checkCycle(adjList,vis,visPath,it)) return true;
            }else if(visPath[it]) return true;
        }
        visPath[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adjList(n);
        for(auto&it:prerequisites){
            int u = it[0];
            int v = it[1];
            adjList[v].push_back(u);
        }
        vector<int>vis(n,0),visPath(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(checkCycle(adjList,vis,visPath,i)) return false;
            }
        }
        for(auto&it:vis){ if(it==0) return false;}
        return true;
    }
};