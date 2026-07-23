class Solution {
    typedef pair<int,int> P;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto&it:times){
            int u =it[0];
            int v =it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<P,vector<P>,greater<P>>pq; //{dist,node}
        pq.push({0,k});
        vector<int>weights(n+1,INT_MAX);
        weights[k] = 0;
        while(!pq.empty()){
            auto[dist,node] = pq.top();
            pq.pop();
            if(dist>weights[node]) continue;
            for(auto&it: adj[node]){
                auto[v,e_wt] = it;
                if(weights[node]+e_wt< weights[v]){
                    weights[v] = weights[node]+e_wt;
                    pq.push({weights[v],v});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(weights[i]==INT_MAX)
                return -1;
            ans = max(ans, weights[i]);
        }
        return ans;
    }
};