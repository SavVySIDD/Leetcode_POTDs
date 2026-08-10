class Solution {
    vector<int>dp;
    bool solve(int n){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        
        for(int i=1;i*i<=n;i++){
            //Call for the other Player(Alice,Bob)
            //Call for BOB if false Bob lost it
            if(!solve(n-i*i)) return dp[n] =true;
        }
        return dp[n] = false;
    }
public:
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return solve(n); //Call for Alice
    }
};