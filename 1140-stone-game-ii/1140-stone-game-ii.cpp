class Solution {
    // P -> Person; 1-> alice, 2->bob
    int dp[3][101][101];
    int solve(vector<int>& piles, int ind, int M, int P){
        int n = piles.size();
        if(ind>=piles.size()) return 0;
        if(dp[P][ind][M]!=-1) return dp[P][ind][M];
        int res = P==1? INT_MIN : INT_MAX; // alice -> INT_MIN, bob ->INT_MAX
        int stone = 0;
        for(int x=1; x<=min(2*M, n-ind); x++){
            stone+= piles[ind+x-1];
            if(P == 1){//Alice
                res = max(res, stone+solve(piles,ind+x,max(M,x),2));
            }else{//Bob
                res = min(res, solve(piles,ind+x,max(M,x),1));
            }
        }
        return dp[P][ind][M]= res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,1,1);
    }
};