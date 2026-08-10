class Solution {
    vector<vector<int>>dp;
    //Player -> 0 : Alice, 1 : Bob
    bool solve(int n, int Player){
        if(n==0 && Player==1) return true;
        if(n==0 && Player==0) return false;
        if(dp[Player][n]!=-1) return dp[Player][n];
        if(Player == 0){ //Alice
            bool res = false;
            for(int i=1;i*i<=n;i++){
                res |=solve(n-(i*i),1);
            }
            return dp[Player][n] = res;
        }else{ //Bob
            bool res = true;
            for(int i=1;i*i<=n;i++){
                res &=solve(n-(i*i),0);
            }
            return dp[Player][n] = res;
        }
        return dp[Player][n] = false;
    }
public:
    bool winnerSquareGame(int n) {
        dp.resize(2,vector<int>(n+1,-1));
        return solve(n,0);
    }
};