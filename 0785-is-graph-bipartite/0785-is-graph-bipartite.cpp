class Solution {
private:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colors){
        colors[node] = color;
        for(auto it: graph[node]){
            if(colors[it]==-1){
                if(!dfs(it,!color,graph,colors)) return false;
            }
            if(colors[it]==color) return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>colors(V,-1);
        for(int i=0;i<V;i++){
            if(colors[i]==-1){
                if(!dfs(i, 0, graph, colors)) return false;
            }
        }
        return true;
    }
};