class Solution {
    class DisjointSet{
        vector<int>size,parent;
    public: 
        DisjointSet(int n){
            size.assign(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        
        int findUParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }
        
        void unionBySize(int u, int v){
            int ultPu = findUParent(u);
            int ultPv = findUParent(v);
            if(ultPu==ultPv){
                return;
            }
            if(size[ultPu] < size[ultPv]){
                parent[ultPu] = ultPv;
                size[ultPv] += size[ultPu];
            }else{
                parent[ultPv] = ultPu;
                size[ultPu] += size[ultPv];
            }
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        
        int extraEdge=0;
        for(auto&it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUParent(u) == ds.findUParent(v)){
                extraEdge++;
            }else{
                ds.unionBySize(u,v);
            }
        }
        
        int totComponents =0;
        for(int i=0;i<n;i++){
            if(ds.findUParent(i)==i) totComponents++;
        }
        // totComponents-1 because we need edges = components-1 to connect
        if(extraEdge>=totComponents-1) return totComponents-1;
        return -1;
    }
};