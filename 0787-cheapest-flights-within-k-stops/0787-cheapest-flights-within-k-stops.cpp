class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&it:flights){
            int u =it[0];
            int v =it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }

        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q; //{stops,{wt,dest}}
        q.push({0,{0,src}});
        dist[src] = 0;
        while(!q.empty()){
            int stops=q.front().first;
            int wt   =q.front().second.first;
            int stop =q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto&it:adj[stop]){
                int v = it.first;
                int c_wt = it.second;
                if(wt+c_wt<dist[v] && stops<=k){
                    dist[v] = wt+c_wt;
                    q.push({stops+1,{c_wt+wt,v}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};