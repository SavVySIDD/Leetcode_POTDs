class Solution {
    typedef pair<long long,int> P;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<P,vector<P>,greater<P>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        int mod=1e9+7;

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();

            if(d>dist[node]) continue;

            for(auto &[v,e_wt]:adj[node]){
                long long currSum=d+e_wt;
                if(currSum<dist[v]){
                    dist[v]=currSum;
                    ways[v]=ways[node];
                    pq.push({dist[v],v});
                }else if(currSum==dist[v]){
                    ways[v]=(ways[v]+ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};